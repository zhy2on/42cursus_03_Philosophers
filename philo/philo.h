/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:09 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/21 18:37:38 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

enum {
	ERROR = 1,
	SUCCESS = 0
};

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	int				eat;
	long long		next_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	long long		begin_at;
	int				done_philo;
	pthread_mutex_t	death_check;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_data;

/*
*** main.c ***
*/
void		free_data(t_data *data);
int			put_error(char *str, t_data *data);

/*
*** init.c ***
*/
long long	get_ms_time(void);
int			ft_atoi(const char *str);
int			init_data(t_data *data, int ac, char **av);
void		init_philo(t_philo *philo, int i, t_data *data);

/*
*** philo.c ***
*/
void		ft_usleep(t_data *data, long long time);
void		print_message(t_philo *philo, char *str);
void		philo_eat(t_philo *philo);
void		*check_death_routine(void *arg);
void		*philo_start_routine(void *arg);

#endif