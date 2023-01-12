/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:55:25 by yewolee           #+#    #+#             */
/*   Updated: 2023/01/06 17:33:26 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_time(void)
{
	struct timeval	time;
	long			ret;

	gettimeofday(&time, NULL);
	ret = ((size_t)time.tv_sec * 1000) + ((size_t)time.tv_usec / 1000);
	return (ret);
}

void	ft_usleep(long sleep_time)
{
	long	start_time;

	start_time = get_time();
	while (start_time + sleep_time > get_time())
		usleep(100);
}
