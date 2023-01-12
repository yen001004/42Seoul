/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:54:33 by yewolee           #+#    #+#             */
/*   Updated: 2023/01/12 19:27:06 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philosopher(t_philo *philo, t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		pthread_mutex_lock(&(args->last_eat_mutex));
		philo[i].last_eat_time = get_time();
		pthread_mutex_unlock(&(args->last_eat_mutex));
		pthread_mutex_lock(&(args->start_time_mutex));
		args->start_time = get_time();
		pthread_mutex_unlock(&(args->start_time_mutex));
		if (pthread_create(&(philo[i].thread), NULL, philo_thread, &(philo[i])))
			return (1);
		i++;
	}
	monitoring(args, philo);
	i = 0;
	while (i < args->philo_num)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (1);
		i++;
	}
	free_thread(args, philo);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6))
		return (1);
	if (init_args(&args, argc, argv))
		return (1);
	if (init_mutex(&args))
		return (1);
	if (init_philos(&philo, &args))
		return (1);
	philosopher(philo, &args);
	return (0);
}
