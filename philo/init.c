/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:47:47 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/20 20:35:44 by jihoh            ###   ########.fr       */
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

int	init_check(t_data *data)
{
	if (data->num_of_philo < 2)
		return (put_error("ERROR: Philosopher must be more than 1\n", data));
	if (data->num_of_philo > 200)
		return (put_error("ERROR: Philosopher must be less than 200\n", data));
	if (data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60)
		return (put_error("ERROR: Time must be more than 60ms\n", data));
	return (SUCCESS);
}

void	init_philo(t_philo *philo, int i, t_data *data)
{
	philo->data = data;
	philo->id = i;
	philo->eat = 0;
	philo->next_meal = philo->data->begin_at + philo->data->time_to_die;
	philo->left = philo->data->forks + i;
	philo->right = philo->data->forks + ((i + 1) % data->num_of_philo);
}

int	init_data(t_data *data, int ac, char **av)
{
	int	i;

	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->done_philo = 0;
	data->forks = NULL;
	data->philos = NULL;
	if (ac == 6)
		data->num_of_must_eat = ft_atoi(av[5]);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->forks || !data->philos)
		return (put_error("ERROR: Malloc Failed\n", data));
	pthread_mutex_init(&data->print, NULL);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_mutex_init(data->forks + i, NULL);
	data->begin_at = get_ms_time();
	i = -1;
	while (++i < data->num_of_philo)
		init_philo(data->philos + i, i, data);
	return (init_check(data));
}
