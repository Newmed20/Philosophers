/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 02:45:51 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 05:53:06 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize_mutexes(t_table *table)
{
	table->mutex_print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	table->mutex_death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	table->mutex_meal = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 1);
	pthread_mutex_init(table->mutex_print, NULL);
	pthread_mutex_init(table->mutex_death, NULL);
	pthread_mutex_init(table->mutex_meal, NULL);
}

void	initialize_philosophers_data(t_table *table, long time, int j)
{
	table->philosophers[j].last_meal = time;
	table->philosophers[j].nbr_of_meals_eaten = 0;
	table->philosophers[j].table = table;
	table->philosophers[j].params = table->params;
	table->philosophers[j].start = time;
	table->philosophers[j].philosopher_id = j + 1;
	table->philosophers[j].left_fork = table->mutex[j];
	table->philosophers[j].right_fork = table->mutex[(j + 1)
		% table->params->num_philosophers];
}

void	initialize_philosophers(t_table *table)
{
	long	time;
	int		j;

	time = ft_time();
	table->philosophers = (t_philo *)malloc(sizeof(t_philo)
			* table->params->num_philosophers);
	table->mutex = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *)
			* table->params->num_philosophers);
	j = 0;
	while (j < table->params->num_philosophers)
	{
		table->mutex[j] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((table->mutex[j]), NULL);
		j++;
	}
	j = 0;
	while (j < table->params->num_philosophers)
	{
		initialize_philosophers_data(table, time, j);
		j++;
	}
}

void	initialize_threads(t_table *table)
{
	int	j;

	table->threads = (pthread_t *)malloc(sizeof(pthread_t)
			* table->params->num_philosophers);
	j = 0;
	while (j < table->params->num_philosophers)
	{
		pthread_create(&table->threads[j], NULL, diner,
			&table->philosophers[j]);
		pthread_detach(table->threads[j]);
		j++;
	}
}

void	initialize_table(t_table *table)
{
	initialize_mutexes(table);
	initialize_philosophers(table);
	initialize_threads(table);
}
