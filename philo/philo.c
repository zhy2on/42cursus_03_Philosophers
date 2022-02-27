/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:38 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/27 16:40:51 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_data *data, long long time)
{
	long long	end;

	end = time + get_ms_time();
	while (data->done_philo < data->num_of_philo)
	{
		if (end <= get_ms_time())
			break ;
		usleep(10);
	}
}

void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->done_philo < philo->data->num_of_philo)
		printf("%lldms\t%d\t%s\n", get_ms_time() - philo->data->begin_at,
			philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left);
	else
		pthread_mutex_lock(philo->right);
	print_message(philo, "has taken a fork");
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right);
	else
		pthread_mutex_lock(philo->left);
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	philo->next_meal = get_ms_time() + philo->data->time_to_die;
	ft_usleep(philo->data, philo->data->time_to_eat);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->data->num_of_must_eat)
		philo->data->done_philo++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	*check_death_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->data->done_philo < philo->data->num_of_philo)
	{
		pthread_mutex_lock(&philo->data->death_check);
		if (philo->next_meal < get_ms_time())
		{
			print_message(philo, "died");
			philo->data->num_of_philo = 0;
			break ;
		}
		pthread_mutex_unlock(&philo->data->death_check);
	}
	return (NULL);
}

void	*philo_start_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death_monitor;

	philo = arg;
	pthread_create(&death_monitor, NULL, check_death_routine, philo);
	pthread_detach(death_monitor);
	while (philo->data->done_philo < philo->data->num_of_philo)
	{
		philo_eat(philo);
		print_message(philo, "is sleeping");
		ft_usleep(philo->data, philo->data->time_to_sleep);
		print_message(philo, "is thinking");
	}
	return (NULL);
}
