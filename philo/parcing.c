/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 02:06:40 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 04:52:19 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argument_values(int time_to_eat, int time_to_sleep, int time_to_die)
{
	if (time_to_eat <= 0 || time_to_sleep <= 0 || time_to_die <= 0)
	{
		ft_putstr_fd("\033[31mError: times should be valid\033[0m\n", 2);
		return (0);
	}
	return (1);
}
int	check_number_of_philosophers(int num_philosophers)
{
	if (num_philosophers <= 0)
	{
		ft_putstr_fd("\033[31mError: Number of philosophers is invalide\033[0m\n", 2);
		return (0);
	}
	return (1);
}
int	check_argument_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("\033[31mError: Invalid number of arguments\033[0m\n", 2);
		return (0);
	}
	return (1);
}




