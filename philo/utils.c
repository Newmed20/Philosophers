/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:47:27 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 05:29:31 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_sleep(int time)
{
	long	start;

	start = ft_time();
	while (ft_time() - start < time)
		usleep(500);
}

long	ft_time(void)
{
	struct timeval	current_time;
	long			time_in_ms;

	gettimeofday(&current_time, NULL);
	time_in_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time_in_ms);
}

int	check_philosopher_death(t_table *table, int index)
{
	if (death_check_time(table, index))
	{
		show_death(table, index);
		death_print(table, index);
		return (1);
	}
	return (0);
}
