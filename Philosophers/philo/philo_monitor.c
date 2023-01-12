/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:53:27 by yewolee           #+#    #+#             */
/*   Updated: 2023/01/04 19:53:31 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_last_eat_time(t_philo *philo)
{
	long	last;

	pthread_mutex_lock(&philo->args->last_eat_mutex);
	last = philo->last_eat_time;
	pthread_mutex_unlock(&philo->args->last_eat_mutex);
	return (last);
}

int	get_min_eat(t_philo *philo, t_args *args)
{
	int	i;
	int	min;
	int	temp;

	i = 0;
	min = INF;
	while (i < args->philo_num)
	{
		pthread_mutex_lock(&args->eat_cnt_mutex);
		temp = philo[i].eat_cnt;
		pthread_mutex_unlock(&args->eat_cnt_mutex);
		if (temp < min)
			min = temp;
		i++;
	}
	return (min);
}

int	check_monitor_mutex(t_args *args)
{
	pthread_mutex_lock(&args->monitor_mutex);
	if (args->monitor_flag == 1)
	{
		pthread_mutex_unlock(&args->monitor_mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&args->monitor_mutex);
		return (0);
	}
}

void	set_monitoring_flag(t_args *args)
{
	pthread_mutex_lock(&args->monitor_mutex);
	args->monitor_flag = 1;
	pthread_mutex_unlock(&args->monitor_mutex);
}

void	monitoring(t_args *args, t_philo *philo)
{
	int		i;
	long	now_time;

	while (!check_monitor_mutex(args))
	{
		if ((args->must_eat_num != 0) && \
		(get_min_eat(philo, args) == args->must_eat_num))
		{
			set_monitoring_flag(args);
			break ;
		}
		i = 0;
		while (i < args->philo_num)
		{
			now_time = get_time();
			if ((now_time - get_last_eat_time(&philo[i])) >= args->life_time)
			{
				philo_print(args, philo[i].id, "died");
				set_monitoring_flag(args);
				break ;
			}
			i++;
		}
	}
}
