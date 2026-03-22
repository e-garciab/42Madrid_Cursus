/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:46:48 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 21:42:06 by egarcia2         ###   ########.fr       */
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

typedef struct s_data	t_data;

/// @brief Represents a single philosopher and its associated thread.
typedef struct s_philo
{
	int					philo_id;
	int					meals_eaten;
	long				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		meal_mutex;
	t_data				*data;
}						t_philo;

/// @brief Holds all shared simulation parameters.
typedef struct s_data
{
	int					nbr_philos;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					nbr_must_eat;
	long				start_time;
	int					simulation_over;
	int					ready;
	pthread_mutex_t		*forks;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		ready_mutex;
	t_philo				*philos;
}						t_data;

/* parser */
int						check_args(int argc, char *argv[], t_data *data);
int						ft_atoi_safe(char *str, long *out);
int						exit_error(char *str);

/* init */
int						init_data(t_data *data);
void					cleanup(t_data *data);

/* utils */
long					get_time_ms(void);
void					ft_usleep(long ms, t_data *data);
int						is_simulation_over(t_data *data);
void					print_state(t_philo *philo, char *state);
int						is_ready(t_data *data);

/*routine*/
int						launch_philos(t_data *data);

/*monitor*/
void					*monitor_routine(void *arg);

#endif /*PHILO_H*/
