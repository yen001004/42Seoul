/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:53:54 by yewolee           #+#    #+#             */
/*   Updated: 2023/01/04 19:53:57 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	philo_eating(t_philo *philo)
{
	philo_print(philo->args, philo->id, "is eating");
	pthread_mutex_lock(&philo->args->last_eat_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->args->last_eat_mutex);
	ft_usleep(philo->args->eat_time);
	pthread_mutex_lock(&philo->args->eat_cnt_mutex);
	philo->eat_cnt++;
	pthread_mutex_unlock(&(philo->args->eat_cnt_mutex));
	pthread_mutex_unlock(&(philo->args->fork[philo->right]));
	pthread_mutex_unlock(&(philo->args->fork[philo->left]));
	if (check_monitor_mutex(philo->args))
		return (1);
	return (0);
}

int	philo_action(t_args *args, t_philo *philo)
{
	if (args->philo_num == 1)
	{
		pthread_mutex_lock(&(args->fork[philo->left]));
		philo_print(args, philo->id, "has taken a fork");
		pthread_mutex_unlock(&(args->fork[philo->left]));
		return (1);
	}
	pthread_mutex_lock(&(args->fork[philo->left]));
	philo_print(args, philo->id, "has taken a fork");
	pthread_mutex_lock(&(args->fork[philo->right]));
	philo_print(args, philo->id, "has taken a fork");
	if (check_monitor_mutex(args))
	{
		pthread_mutex_unlock(&(args->fork[philo->left]));
		pthread_mutex_unlock(&(args->fork[philo->right]));
		return (1);
	}
	return (0);
}

void	*philo_thread(void *data)
{
	t_args	*args;
	t_philo	*philo;

	philo = data;
	args = philo->args;
	if (philo->id % 2 == 0)
		usleep(100);
	while (!check_monitor_mutex(args))
	{
		if (philo_action(args, philo))
			break ;
		if (philo_eating(philo))
			break ;
		philo_print(args, philo->id, "is sleeping");
		ft_usleep((long)args->sleep_time);
		if (check_monitor_mutex(args))
			break ;
		philo_print(args, philo->id, "is thinking");
	}
	return (0);
}

void	free_thread(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->philo_num)
	{
		pthread_mutex_destroy(&(args->fork[i]));
		i++;
	}
	free(philo);
	free(args->fork);
	pthread_mutex_destroy(&(args->print_mutex));
}
