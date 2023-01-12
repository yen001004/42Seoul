/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:55:12 by yewolee           #+#    #+#             */
/*   Updated: 2023/01/12 19:27:57 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_print(t_args *args, int id, char *str)
{
	long	now_time;
	int		flag;

	now_time = get_time();
	pthread_mutex_lock(&(args->print_mutex));
	pthread_mutex_lock(&(args->monitor_mutex));
	flag = args->monitor_flag;
	pthread_mutex_unlock(&(args->monitor_mutex));
	if (!flag)
	{
		pthread_mutex_lock(&(args->start_time_mutex));
		printf("%ld %d %s\n", now_time - args->start_time, id, str);
		pthread_mutex_unlock(&(args->start_time_mutex));
	}
	pthread_mutex_unlock(&(args->print_mutex));
}
