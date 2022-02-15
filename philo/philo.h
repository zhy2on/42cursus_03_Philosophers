/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:09 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/15 18:18:30 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				idx;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_data	*data;
	double			time;
}				t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	pthread_mutex_t	eating;
	pthread_mutex_t	*forks;
	long long		begin;
	t_philo			*philos;
}				t_data;

/*
*** init.c ***
*/
void	init_data(t_data *data, int ac, char **av);
void	init_philo(t_philo *philo, int i, t_data *data);

/*
*** philo.c ***
*/
void	*philo_start_routine(void *arg);

/*
*** utils.c ***
*/
int		ft_atoi(const char *str);
void	handle_error(char *str, int len);
void	print_message(t_philo *philo, char *str);
void	get_time_of_ms(long long *time);

/*
*** test.c ***
*/
void	*test(void	*arg);

#endif