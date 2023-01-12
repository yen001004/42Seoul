/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewolee <yewolee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 19:54:51 by yewolee           #+#    #+#             */
/*   Updated: 2023/01/12 19:19:41 by yewolee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define INF 987654321

typedef struct s_args {
	int				philo_num;
	int				life_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat_num;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	monitor_mutex;
	pthread_mutex_t	eat_cnt_mutex;
	pthread_mutex_t	last_eat_mutex;
	pthread_mutex_t	start_time_mutex;
	pthread_mutex_t	*fork;
	int				monitor_flag;
	long			start_time;

}	t_args;

typedef struct s_philo {
	int			id;
	int			eat_cnt;
	int			left;
	int			right;
	long		last_eat_time;
	pthread_t	thread;
	t_args		*args;
}	t_philo;

// philo_init.c
int		init_args(t_args *args, int argc, char **argv);
int		init_mutex(t_args *args);
int		init_philos(t_philo **philo, t_args *args);

// philo_monitor.c
int		get_min_eat(t_philo *philo, t_args *args);
int		check_monitor_mutex(t_args *args);
void	set_monitoring_flag(t_args *args);
void	monitoring(t_args *args, t_philo *philo);

// philo_print.c
void	philo_print(t_args *args, int id, char *str);

// philo_thread.c
int		philo_eating(t_philo *philo);
int		philo_action(t_args *args, t_philo *philo);
void	*philo_thread(void *argv);
void	free_thread(t_args *args, t_philo *philo);

// philo_time.c
long	get_time(void);
void	ft_usleep(long sleep_time);

// philo_utils.c
int		ft_atoi(char *str);

// philosopher.c
int		philosopher(t_philo *philo, t_args *args);

#endif
