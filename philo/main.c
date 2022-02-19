/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:11:05 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/19 16:39:36 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	handle_error(char *str, int len)
{
	write(1, str, len);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac != 5 && ac != 6)
		handle_error("Wrong parameters\n", 16);
	init_data(&data, ac, av);i = -1;
	while (++i < data.num_of_philo)
		pthread_create(&data.philos[i].tid, NULL,
			philo_start_routine, data.philos + i);
	i = -1;
	while (++i < data.num_of_philo)
		pthread_join(data.philos[i].tid, NULL);
	free(data.philos);
	free(data.forks);
	exit(0);
}
