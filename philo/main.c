/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:11:05 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/15 18:54:30 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac != 5 && ac != 6)
		handle_error("Wrong parameters\n", 16);
	init_data(&data, ac, av);
	i = -1;
	while (++i < data.num_of_philo)
		pthread_create(&data.philos[i].thread, NULL,
			philo_start_routine, data.philos + i);
	i = -1;
	while (++i < data.num_of_philo)
		pthread_join(data.philos[i].thread, NULL);
	exit(0);
}
