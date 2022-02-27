/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:43:15 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/27 19:04:42 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_data(t_data *data)
{
	if (data->philos)
		free(data->philos);
	sem_close(data->death_check);
	sem_close(data->print);
	sem_close(data->pause);
	sem_close(data->forks);
	sem_close(data->done_philo);
}

void	*check_eat_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = arg;
	i = -1;
	while (++i < data->num_of_philo)
		sem_wait(data->done_philo);
	sem_post(data->pause);
	return (NULL);
}

void	handle_error(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	if (data)
		free_data(data);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	eat_monitor;
	int			i;

	if (ac != 5 && ac != 6)
		handle_error("ERROR: Wrong parameters\n", NULL);
	init_data(&data, ac, av);
	pthread_create(&eat_monitor, NULL, check_eat_routine, &data);
	pthread_detach(eat_monitor);
	i = -1;
	while (++i < data.num_of_philo)
	{
		data.philos[i].pid = fork();
		if (data.philos[i].pid == 0)
			philo_start_routine(data.philos + i);
	}
	sem_wait(data.pause);
	i = -1;
	while (++i < data.num_of_philo)
		kill(data.philos[i].pid, SIGKILL);
	free_data(&data);
	return (0);
}
