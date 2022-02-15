/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:54:18 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/15 17:54:05 by jihoh            ###   ########.fr       */
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

void	handle_error(char *str, int len)
{
	write(1, str, len);
	exit(1);
}

void	get_time_of_ms(long long *time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*time = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
}

void	print_message(t_philo *philo, char *str)
{
	long long	time;

	get_time_of_ms(&time);
	printf("%lld %d %s\n", time - philo->data->begin, philo->idx + 1, str);
}
