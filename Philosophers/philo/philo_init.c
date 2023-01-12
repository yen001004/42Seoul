/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:55:01 by yewolee           #+#    #+#             */
/*   Updated: 2023/01/12 19:20:08 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	init_args(t_args *args, int argc, char **argv)
{
	args->philo_num = ft_atoi(argv[1]);
	args->life_time = ft_atoi(argv[2]);
	args->eat_time = ft_atoi(argv[3]);
	args->sleep_time = ft_atoi(argv[4]);
	args->monitor_flag = 0;
	if (args->philo_num <= 0)
		return (1);
	if (args->life_time < 0 || args->eat_time < 0 || args->sleep_time < 0)
		return (1);
	if (argc == 6)
	{
		args->must_eat_num = ft_atoi(argv[5]);
		if (args->must_eat_num <= 0)
			return (1);
	}
	else
		args->must_eat_num = 0;
	return (0);
}

int	init_mutex(t_args *args)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(args->print_mutex), NULL) == -1 || \
	pthread_mutex_init(&(args->monitor_mutex), NULL) == -1 || \
	pthread_mutex_init(&(args->start_time_mutex), NULL) == -1 || \
	pthread_mutex_init(&(args->eat_cnt_mutex), NULL) == -1 || \
	pthread_mutex_init(&(args->last_eat_mutex), NULL) == -1)
		return (1);
	args->fork = malloc(sizeof(pthread_mutex_t) * args->philo_num);
	if (args->fork == 0)
		return (1);
	while (i < args->philo_num)
	{
		if (pthread_mutex_init(&(args->fork[i]), NULL) == -1)
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_philo **philo, t_args *args)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * args->philo_num);
	if (philo == 0)
		return (1);
	while (i < args->philo_num)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].eat_cnt = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % args->philo_num;
		(*philo)[i].last_eat_time = 0;
		(*philo)[i].args = args;
		i++;
	}
	return (0);
}
