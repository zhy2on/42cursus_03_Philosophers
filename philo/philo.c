/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:38 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/19 16:52:51 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_ms_time(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
	return (time);
}

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
	printf("%lldms\t%d\t%s\n", get_ms_time() - philo->data->begin,
		philo->id + 1, str);
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
	ft_usleep(philo->data, philo->data->time_to_eat);
	philo->eat++;
	if (philo->eat == philo->data->num_of_must_eat)
		philo->data->done_philo++;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	*philo_start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (philo->data->done_philo < philo->data->num_of_philo)
	{
		philo_eat(philo);
		print_message(philo, "is sleeping");
		ft_usleep(philo->data, philo->data->time_to_sleep);
		print_message(philo, "is thinking");
	}
	return (NULL);
}
