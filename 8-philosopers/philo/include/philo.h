/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:46:48 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/15 21:14:49 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>


// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
typedef struct s_data   t_data;

typedef struct s_philo
{
    int philo_id;
    int meals_eaten;
    long last_meal_time;
    pthread_t thread; //el hilo de cada philo
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t meal_mutex; //protege last_meal_time y meals_eaten ??
    t_data *data;    
}   t_philo;

typedef struct s_data
{
    int nbr_philos;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int nbr_must_eat; //[number_of_times_each_philosopher_must_eat]
    long start_time;
    int simulation_over; //0 corriendo; 1 teminada
    pthread_mutex_t *forks; //array de mutex (forks) (serán los candados con mutex)
    pthread_mutex_t death_mutex; // protege end_simulation ??
    pthread_mutex_t print_mutex; // protege los prints ??
    t_philo *philos; //array de philos
}   t_data;

/* parser */
int	ft_atoi_safe(char *str, long *out);
int check_args (int argc, char *argv[], t_data *data);

/* init */
int init_data(t_data *data);
void    cleanup(t_data *data);

/* utils */
int exit_error(char *str);
long get_time_ms();
void ft_usleep (long ms, t_data *data);
int is_simulation_over(t_data *data);
void print_state(t_philo *philo, char *state);

/*routine*/
int launch_philos(t_data *data);
int join_philos(t_data *data);

/*monitor*/
void *monitor_routine(void *arg);

#endif /*PHILO_H*/

