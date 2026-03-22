/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:01:13 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 13:15:15 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long get_think_time(t_philo *philo)
{
    long think_time;

    think_time = philo->data->time_to_die
        - philo->data->time_to_eat
        - philo->data->time_to_sleep;
    if (think_time < 0)
        think_time = 0;
    return (think_time / 2);
}
// static long get_think_time(t_philo *philo)
// {
//     long think_time;

//     think_time = philo->data->time_to_die
//         - philo->data->time_to_eat
//         - philo->data->time_to_sleep;
//     if (think_time < 0)
//         think_time = 0;
//     if (philo->data->nbr_philos % 2 == 0)
//         return (think_time / 2);
//     return (think_time / 3);
// }

static void philo_think(t_philo *philo)
{
    print_state(philo, "is thinking");
    ft_usleep(get_think_time(philo), philo->data);
}

static void one_philo(t_philo *philo)
{
    print_state(philo, "has taken a fork");
    ft_usleep(philo->data->time_to_die, philo->data);   
}

static void philo_eat(t_philo *philo)
{
    pthread_mutex_t *first;
    pthread_mutex_t *second;
    
    if(philo->left_fork < philo->right_fork)
    {
        first = philo->left_fork;
        second = philo->right_fork;
    }
    else
    {
        first = philo->right_fork;
        second = philo->left_fork;
    }
    pthread_mutex_lock(first);
    print_state(philo, "has taken a fork");
    pthread_mutex_lock(second);
    print_state(philo, "has taken a fork");
    print_state(philo, "is eating");
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time=get_time_ms();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_mutex);
    ft_usleep(philo->data->time_to_eat, philo->data);
    pthread_mutex_unlock(second);
    pthread_mutex_unlock(first);
}

void *routine(void *arg)
{
    t_philo *philo; 
    
    philo = (t_philo *)arg; //¿¿¿????
    while(!is_ready(philo->data))
        continue;
    if(philo->data->nbr_philos == 1)
    {
        one_philo(philo);
        return(NULL);
    }
    // Retraso inicial — pares esperan 1ms, impares esperan más
    if(philo->philo_id %2 == 0) //si es un nº de philo par
        ft_usleep(philo->data->time_to_eat, philo->data);
    // else if (philo->philo_id == philo->data->nbr_philos && philo->data->nbr_philos % 2 != 0)
    //     ft_usleep(philo->data->time_to_eat / 2, philo->data);
    // else if(philo->data->nbr_philos %2 != 0)
    // {
    // // Con número impar de filósofos el último impar espera más
    //     if (philo->philo_id == philo->data->nbr_philos)
    //         ft_usleep(philo->data->time_to_eat, philo->data);
    // }
    while(!is_simulation_over(philo->data))
    {
        philo_eat(philo);
        if(is_simulation_over(philo->data))
            break; 
        print_state(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep, philo->data);
        if(is_simulation_over(philo->data))
            break;
        philo_think(philo);
        // print_state(philo, "is thinking");
    }
    return(NULL);
}

int launch_philos(t_data *data)
{
    int i; 

    i=0;
    // Primero crea TODOS los hilos
    while(i < data->nbr_philos)
    {
        if(pthread_create(&data->philos[i].thread, NULL, routine, &data ->philos[i]) != 0)
            return (0);
        i++;
    }
    // DESPUÉS inicializa los tiempos y activa ready
    data->start_time = get_time_ms();
    i = 0;
    while (i < data->nbr_philos)
    {
        data->philos[i].last_meal_time = data->start_time;
        i++;
    }
    pthread_mutex_lock(&data->ready_mutex);
    data->ready = 1;
    pthread_mutex_unlock(&data->ready_mutex);
    return(1);
}

int join_philos(t_data *data)
{
    int i;

    i=0;
    while (i < data->nbr_philos)
    {
        if(pthread_join(data->philos[i].thread, NULL) != 0)
            return(0);
        i++;
    }
    return(1);
}



