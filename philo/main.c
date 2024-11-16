/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 02:39:07 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 05:51:26 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parcing_arguments(int argc, char *argv[], t_table *table)
{
	table->params = malloc(sizeof(t_params));
	if (!check_argument_count(argc))
		return (0);
	table->params->num_philosophers = ft_atoi(argv[1]);
	if (!check_number_of_philosophers(table->params->num_philosophers))
		return (0);
	table->params->time_to_eat = ft_atoi(argv[3]);
	table->params->time_to_sleep = ft_atoi(argv[4]);
	table->params->time_to_die = ft_atoi(argv[2]);
	if (!check_argument_values(table->params->time_to_eat,
			table->params->time_to_sleep, table->params->time_to_die))
		return (0);
	if (argc == 6)
	{
		table->params->ntpm_eat = ft_atoi(argv[5]);
		if (table->params->ntpm_eat <= 0)
		{
			ft_putstr_fd("  Invalid argument\n", 2);
			return (0);
		}
	}
	else
		table->params->ntpm_eat = -1;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!parcing_arguments(argc, argv, table))
		return (1);
	initialize_table(table);
	while (1)
	{
		if (is_simulation_finished(table))
			return (1);
	}
	free(table->philosophers);
	free(table->mutex);
	free(table->threads);
	free(table->mutex_print);
	free(table->mutex_death);
	free(table->mutex_meal);
	free(table);
}