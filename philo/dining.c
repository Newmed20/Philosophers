/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 02:42:23 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 05:49:49 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status_print(t_philo *philo, char *message)
{
	t_table	*table;

	table = (t_table *)philo->table;
	pthread_mutex_lock(table->mutex_print);
	printf("%ld %d %s\n", ft_time() - philo->start,
		philo->philosopher_id, message);
	pthread_mutex_unlock(table->mutex_print);
}
void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	status_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	status_print(philo, "has taken a fork");
}

void	eat(t_philo *philo, t_table *table)
{
	status_print(philo, "is eating");
	pthread_mutex_lock(table->mutex_meal);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(table->mutex_meal);
	ft_sleep(table->params->time_to_eat);
	pthread_mutex_lock(table->mutex_meal);
	philo->nbr_of_meals_eaten += 1;
	pthread_mutex_unlock(table->mutex_meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*diner(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = (t_table *)philo->table;
	if (philo->philosopher_id % 2 != 0)
		usleep(500);
	while (1)
	{
		status_print(philo, "is thinking");
		take_forks(philo);
		eat(philo, table);
		status_print(philo, "is sleeping");
		ft_sleep(table->params->time_to_sleep);
	}
	return (NULL);
}