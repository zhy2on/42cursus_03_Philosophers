/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:50:13 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/27 19:05:38 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(long long time)
{
	long long	end;

	end = time + get_ms_time();
	while (1)
	{
		if (end <= get_ms_time())
			break ;
		usleep(10);
	}
}

void	print_message(t_philo *philo, char *str)
{
	sem_wait(philo->data->print);
	printf("%lldms\t%d\t%s\n", get_ms_time() - philo->data->begin_at,
		philo->id + 1, str);
	if (*str != 'd')
		sem_post(philo->data->print);
}

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_message(philo, "has taken a fork");
	sem_wait(philo->data->forks);
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	philo->next_meal = get_ms_time() + philo->data->time_to_die;
	ft_usleep(philo->data->time_to_eat);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->data->num_of_must_eat)
		sem_post(philo->data->done_philo);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	*check_death_routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = arg;
	while (1)
	{
		sem_wait(philo->data->death_check);
		if (philo->next_meal < get_ms_time())
		{
			print_message(philo, "died");
			i = -1;
			while (++i < philo->data->num_of_philo)
				sem_post(philo->data->done_philo);
			break ;
		}
		sem_post(philo->data->death_check);
	}
	return (NULL);
}

void	philo_start_routine(t_philo *philo)
{
	pthread_t	death_monitor;

	pthread_create(&death_monitor, NULL, check_death_routine, philo);
	pthread_detach(death_monitor);
	while (1)
	{
		philo_eat(philo);
		print_message(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print_message(philo, "is thinking");
	}
	exit(0);
}
