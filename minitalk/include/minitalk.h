/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:33:44 by yewolee           #+#    #+#             */
/*   Updated: 2022/07/16 13:18:49 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"

# include <signal.h>
# include <unistd.h>

typedef struct s_buffer
{
	char	buf;
	int		cnt;
}	t_buffer;

void	sig_send(int pid, int sig);
void	conv_to_binary(int pid, unsigned char c, int len);
void	convert_msg(int pid, char *msg);

void	sig_handler(int signo);

#endif
