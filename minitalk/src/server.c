/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:28:40 by yewolee           #+#    #+#             */
/*   Updated: 2022/07/16 13:21:22 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_buffer	g_buffer;

void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		g_buffer.buf |= (1 << g_buffer.cnt);
	}
	else if (signo == SIGUSR2)
	{
		g_buffer.buf &= ~(1 << g_buffer.cnt);
	}
	g_buffer.cnt--;
	if (g_buffer.cnt == -1)
	{
		g_buffer.cnt = 7;
		write(1, &g_buffer.buf, 1);
		g_buffer.buf = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	g_buffer.buf = 0;
	g_buffer.cnt = 7;
	ft_printf("PID : %d\n", getpid());
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = 0;
	sigact.sa_handler = sig_handler;
	if (sigaction(SIGUSR1, &sigact, 0) != 0)
	{
		ft_printf("Sigaction Error\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &sigact, 0) != 0)
	{
		ft_printf("Sigaction Error\n");
		exit(1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
