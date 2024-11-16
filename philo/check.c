/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 02:48:55 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 05:49:32 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	death_check_time(t_table *table, int p_index)
{
	long	current_time;
	long	diff;

	pthread_mutex_lock(table->mutex_meal);
	current_time = ft_time();
	diff = current_time - table->philosophers[p_index].last_meal;
	pthread_mutex_unlock(table->mutex_meal);
	return (diff > table->params->time_to_die);
}

int	done_eatin(t_table *t, int p_index)
{
	int	meals_eaten;

	meals_eaten = t->philosophers[p_index].nbr_of_meals_eaten;
	pthread_mutex_lock(t->mutex_meal);
	pthread_mutex_unlock(t->mutex_meal);
	return (t->params->ntpm_eat != -1
		&& meals_eaten >= t->params->ntpm_eat);
}

void	show_death(t_table *table, int i)
{
	pthread_mutex_lock(table->mutex_death);
	table->is_philosopher_dead = 1;
	pthread_mutex_unlock(table->mutex_death);
	table->philo_dead_id = table->philosophers[i].philosopher_id;
}

void	death_print(t_table *table, int index)
{
	pthread_mutex_lock(table->mutex_print);
	printf("%ld %d died\n", (ft_time() - table->philosophers[index].start),
		table->philo_dead_id);
	pthread_mutex_unlock(table->mutex_print);
}

int	is_simulation_finished(t_table *table)
{
	int	i;
	int	check;
	int	is_dead;

	is_dead = 0;
	pthread_mutex_lock(table->mutex_death);
	is_dead = table->is_philosopher_dead;
	pthread_mutex_unlock(table->mutex_death);
	if (is_dead)
		return (1);
	i = 0;
	check = 0;
	while (i < table->params->num_philosophers)
	{
		if (check_philosopher_death(table, i))
			return (1);
		if (done_eatin(table, i))
		{
			check += 1;
			if (check >= table->params->num_philosophers)
				return (1);
		}
		i++;
	}
	return (0);
}
