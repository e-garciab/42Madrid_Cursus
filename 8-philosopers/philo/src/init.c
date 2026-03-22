/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 20:47:41 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 12:43:40 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_forks(t_data *data)
{
    int i; 

    i=0;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
    if(!data->forks)
        return (0);
    while (i < data->nbr_philos)
    {
        if(pthread_mutex_init(&data->forks[i], NULL) != 0)
        {
            free(data->forks);
            data->forks = NULL;
            return(0);
        }
        i++;
    }
    return(1);
}

static int init_philos(t_data *data)
{
    int i; 
    
    i=0;
    data->philos = malloc(sizeof(t_philo) * data->nbr_philos);
    if(!data->philos)
        return(0);
    while(i < data->nbr_philos)
    {
        data->philos[i].philo_id = i + 1;
        data->philos[i].meals_eaten = 0;
        data->philos[i].last_meal_time = 0; // ???
        data->philos[i].data = data;
        data->philos[i].left_fork = &data->forks[i];
        data->philos[i].right_fork = &data->forks[(i+1) % data->nbr_philos];
        if(pthread_mutex_init(&data->philos[i].meal_mutex, NULL) != 0)
        {
            free(data->forks);
            data->forks = NULL;
            return(0);
        }
        i++;  
    }
    return(1);
}

int init_data(t_data *data)
{
    data->forks = NULL;
    data->philos = NULL;
    data->start_time = 0;
    data->simulation_over = 0;
    data->ready = 0;
    if(!init_forks(data))
        return(0);
    if(!init_philos(data))
        return(0);
    if(pthread_mutex_init(&data->death_mutex, NULL) != 0)
        return(0);
    if(pthread_mutex_init(&data->print_mutex, NULL) != 0)
        return(0);
    if(pthread_mutex_init(&data->ready_mutex, NULL) != 0)
        return(0);
    return(1);
}

void    cleanup(t_data *data)
{
    int i;

    i = 0;
    if(data->forks && data->philos)
    {
        while (i < data->nbr_philos)
        {
            pthread_mutex_destroy(&data->forks[i]);
            pthread_mutex_destroy(&data->philos[i].meal_mutex);
            i++;
        }
    }
    pthread_mutex_destroy(&data->death_mutex);
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->ready_mutex);
    if(data->forks)
        free(data->forks);
    if(data->philos)
        free(data->philos);
}
