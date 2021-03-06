/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:11:05 by jihoh             #+#    #+#             */
/*   Updated: 2022/04/18 21:29:59 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	usleep(1000);
	i = -1;
	while (++i < data->num_of_philo)
		pthread_mutex_destroy(data->forks + i);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death_check);
	pthread_mutex_destroy(&data->pause);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

int	put_error(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	if (data)
		free_data(data);
	return (ERROR);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac != 5 && ac != 6)
		return (put_error("ERROR: Wrong parameters\n", NULL));
	if (init_data(&data, ac, av) == ERROR)
		return (1);
	i = -1;
	while (++i < data.num_of_philo)
	{
		pthread_create(&data.philos[i].tid, NULL,
			philo_start_routine, data.philos + i);
		pthread_detach(data.philos[i].tid);
	}
	pthread_mutex_lock(&data.pause);
	free_data(&data);
	return (0);
}
