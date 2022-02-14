/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:11:05 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/14 19:04:17 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test(void	*arg)
{
	t_philo	*philo;

	philo = arg;
	printf("philo id %d\n", philo->idx);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;

	if (ac != 5 && ac != 6)
		handle_error("Wrong parameters\n", 16);
	init_data(&data, ac, av);
	init_philos(&data, data.philos);
	i = -1;
	while (++i < data.num_of_philo)
	{
		pthread_create(&data.philos[i].thread, NULL, test, data.philos + i);
		pthread_detach(data.philos[i].thread);
	}
	exit(0);
}
