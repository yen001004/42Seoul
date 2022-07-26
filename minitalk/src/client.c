/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:29:12 by yewolee           #+#    #+#             */
/*   Updated: 2022/07/16 13:16:53 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_send(int pid, int sig)
{
	if (sig == 1)
	{
		kill(pid, SIGUSR1);
	}
	if (sig == 0)
	{
		kill(pid, SIGUSR2);
	}
	usleep(500);
}

void	conv_to_binary(int pid, unsigned char c, int len)
{
	if (c == 0)
	{
		while (len++ < 8)
		{
			sig_send(pid, 0);
		}
		return ;
	}
	else
	{
		conv_to_binary(pid, c / 2, ++len);
		sig_send(pid, c % 2);
	}
}

void	convert_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		conv_to_binary(pid, (unsigned char)msg[i], 0);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		return (0);
	}
	ft_printf("client PID : %d\n", getpid());
	ft_printf("server PID : %s\n", av[1]);
	ft_printf("Message    : %s\n", av[2]);
	convert_msg(ft_atoi(av[1]), av[2]);
	return (0);
}
