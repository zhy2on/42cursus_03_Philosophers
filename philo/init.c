/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:47:47 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/19 16:02:49 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned int	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	return (sign * num);
}

void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->id = i;
	philo->eat = 0;
	philo->data = data;
	philo->left = philo->data->forks + i;
	philo->right = philo->data->forks + ((i + 1) % data->num_of_philo);
}

void	init_data(t_data *data, int ac, char **av)
{
	int				i;

	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->done_philo = 0;
	if (ac == 6)
		data->num_of_must_eat = ft_atoi(av[5]);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_mutex_init(data->forks + i, NULL);
	data->philos = malloc(sizeof(t_philo) * data->num_of_philo);
	i = -1;
	while (++i < data->num_of_philo)
		init_philo(data->philos + i, i, data);
	data->begin = get_ms_time();
}
