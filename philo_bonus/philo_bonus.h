/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:00:30 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/27 18:13:51 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <signal.h>

enum {
	ERROR = 1,
	SUCCESS = 0
};

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	int				eat_cnt;
	long long		next_meal;
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
	sem_t			*death_check;
	sem_t			*print;
	sem_t			*pause;
	sem_t			*forks;
	sem_t			*done_philo;
	t_philo			*philos;
}				t_data;

/*
*** main.c ***
*/
void		free_data(t_data *data);
void		handle_error(char *str, t_data *data);

/*
*** init.c ***
*/
long long	get_ms_time(void);
int			ft_atoi(const char *str);
void		init_data_sub(t_data *data);
void		init_data(t_data *data, int ac, char **av);

/*
*** philo.c ***
*/
void		ft_usleep(t_data *data, long long time);
void		print_message(t_philo *philo, char *str);
void		philo_eat(t_philo *philo);
void		*check_death_routine(void *arg);
void		philo_start_routine(t_philo *philo);

#endif