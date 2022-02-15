/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:18:21 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/15 19:29:10 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	long long	end;

	end = time + get_ms_time();
	while (end > get_ms_time())
		usleep(10);
}
