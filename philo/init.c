/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:47:47 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/14 19:01:54 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_data *data, t_philo *philo)
{
	int	i;

	philo = malloc(sizeof(t_philo) * data->num_of_philo);
	i = -1;
	while (++i < data->num_of_philo)
	{
		philo[i].idx = i;
		philo[i].left = i;
		philo[i].right = (i + 1) % data->num_of_philo;
	}
}

void	init_data(t_data *data, int ac, char **av)
{
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_of_must_eat = ft_atoi(av[5]);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->num_of_philo);
}
