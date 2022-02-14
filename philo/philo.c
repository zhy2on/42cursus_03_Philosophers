/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:38 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/14 19:04:38 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(void)
{
	return ;
}

void	philo_eat(void)
{
	return ;
}

void	philo_sleep(void)
{
	return ;
}

void	philo_think(void)
{
	return ;
}

void	*philo_do(t_data *data)
{
	/*
	if (philo->idx % 2 == 0)
		usleep(data->time_to_eat * 1000);
	*/
	printf("philo work\n");
	philo_take_forks();
	philo_eat();
	philo_sleep();
	philo_think();
	return (NULL);
}
