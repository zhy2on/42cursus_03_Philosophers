/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:47:47 by jihoh             #+#    #+#             */
/*   Updated: 2022/04/18 20:28:35 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	init_data_sub(t_data *data)
{
	int		i;
	t_philo	*philo;

	data->print = sem_open("print", O_CREAT, 0600, 1);
	data->death_check = sem_open("death_check", O_CREAT, 0600, 1);
	data->forks = sem_open("forks", O_CREAT, 0600, data->num_of_philo);
	data->pause = sem_open("pause", O_CREAT, 0600, 0);
	data->done_philo = sem_open("done_philo", O_CREAT, 0600, 0);
	data->begin_at = get_ms_time();
	i = -1;
	while (++i < data->num_of_philo)
	{
		philo = data->philos + i;
		philo->data = data;
		philo->id = i;
		philo->eat_cnt = 0;
		philo->next_meal = data->begin_at + data->time_to_die;
	}
}

void	init_data(t_data *data, int ac, char **av)
{
	data->num_of_philo = ft_atoi(av[1]);
	if (data->num_of_philo < 1)
		handle_error("ERROR: Philosophers must be more than one\n", NULL);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->num_of_must_eat = -1;
	if (ac == 6)
		data->num_of_must_eat = ft_atoi(av[5]);
	sem_unlink("print");
	sem_unlink("death_check");
	sem_unlink("forks");
	sem_unlink("pause");
	sem_unlink("done_philo");
	data->philos = NULL;
	data->philos = malloc(sizeof(t_philo) * data->num_of_philo);
	if (!data->philos)
		handle_error("ERROR: Malloc failed\n", data);
	init_data_sub(data);
}
