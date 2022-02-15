/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:47:47 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/15 18:52:14 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->idx = i;
	philo->data = data;
	philo->left = philo->data->forks + i;
	philo->right = philo->data->forks + ((i + 1) % data->num_of_philo);
}

void	init_data(t_data *data, int ac, char **av)
{
	int				i;

	get_time_of_ms(&data->begin);
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->num_of_must_eat = ft_atoi(av[5]);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_mutex_init(data->forks + i, NULL);
	pthread_mutex_init(&data->eating, NULL);
	data->philos = malloc(sizeof(t_philo) * data->num_of_philo);
	i = -1;
	while (++i < data->num_of_philo)
		init_philo(data->philos + i, i, data);
}
