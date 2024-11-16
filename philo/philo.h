/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjadid <mjadid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 02:06:54 by mjadid            #+#    #+#             */
/*   Updated: 2024/11/16 05:50:22 by mjadid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_params
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				ntpm_eat;
}					t_params;

typedef struct philosophers
{
	int				nbr_of_meals_eaten;
	int				philosopher_id;
	t_params			*params;
	int				ntpm_eat;
	long			start;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	void			*table;
}					t_philo;

typedef struct Diningtable
{
	t_philo		*philosophers;
	pthread_mutex_t		**mutex;
	pthread_t			*threads;
	t_params				*params;
	int					is_philosopher_dead;
	int					philo_dead_id;
	pthread_mutex_t		*mutex_print;
	pthread_mutex_t		*mutex_death;
	pthread_mutex_t		*mutex_meal;
}	t_table;

int                 check_argument_count(int argc);
int                 check_number_of_philosophers(int num_philosophers);
int                 check_argument_values(int time_to_eat, int time_to_sleep, int time_to_die);
int					parcing_arguments(int argc, char *argv[],t_table *table);
void				ft_putstr_fd(char *s, int fd);
long				ft_time(void);
int					is_simulation_finished(t_table *philo);
int					ft_atoi(char *str);
int					ft_isdigit(int ch);
int					ft_strlen(char *str);
void				ft_sleep(int time);
long				ft_time(void);
void				*diner(void *arg);
int					death_check_time(t_table *table, int p_index);
int					done_eatin(t_table *t,int p_index);
int					is_simulation_finished(t_table *table);
void				initialize_mutexes(t_table *table);
void				initialize_philosophers(t_table *table);
void				initialize_threads(t_table *table);
void				initialize_table(t_table *table);
int					check_philosopher_death(t_table *table, int index);
void				show_death(t_table *table, int i);
void				death_print(t_table *table, int index);


#endif
