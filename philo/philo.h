/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:10:09 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/14 18:57:30 by jihoh            ###   ########.fr       */
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
	pthread_t		thread;
	pthread_mutex_t	*eat;
	int				idx;
	int				left;
	int				right;
}				t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_data;

void	init_data(t_data *data, int ac, char **av);
int		ft_atoi(const char *str);
void	handle_error(char *str, int len);
void	init_philos(t_data *data, t_philo *philo);
void	*philo_do(t_data *data);

#endif