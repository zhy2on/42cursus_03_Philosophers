/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:38 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/15 19:30:35 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *philo)
{
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	print_message(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	*philo_start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->data->eating);
	philo_take_forks(philo);
	philo_eat(philo);
	pthread_mutex_unlock(&philo->data->eating);
	philo_sleep(philo);
	philo_think(philo);
	return (NULL);
}
