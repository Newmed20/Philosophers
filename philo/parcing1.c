/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:44:16 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 05:44:11 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_sign(char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '+' || str[*index] == '-')
	{
		if (str[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	return (sign);
}

int	to_int(char *str, int *index)
{
	int	res;
	int	s;

	s = 0;
	res = 0;
	while (str[*index])
	{
		if (!ft_isdigit(str[*index]))
		{
			ft_putstr_fd("Error :\n", 2);
			return (0);
		}
		res *= 10;
		res = (res + str[*index]) - '0';
		(*index)++;
	}
	return (res);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (ft_strlen(str) == 1 && (str[0] == '+' || str[0] == '-'))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\r')
		i++;
	sign = ft_sign(str, &i);
	res = to_int(str, &i);
	res = res * sign;
	if (res < INT_MIN || res > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (res);
}
