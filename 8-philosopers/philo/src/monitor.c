/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:49:51 by egarcia2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/15 22:16:06 by egarcia2         ###   ########.fr       */
=======
/*   Updated: 2026/03/17 20:48:14 by egarcia2         ###   ########.fr       */
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

<<<<<<< HEAD
static int philo_died(t_philo *philo)
{
    long time_since_last_meal;
    
    pthread_mutex_lock(&philo->meal_mutex);
    time_since_last_meal = get_time_ms() - philo->last_meal_time;
    pthread_mutex_unlock(&philo->meal_mutex);
    if(time_since_last_meal > philo->data->time_to_die)
        return(1);
    return(0);
}
//Necesita el meal_mutex porque last_meal_time la escribe el filósofo en philo_eat() y la lee el monitor aquí — acceso concurrente → mutex obligatorio.

static int all_philos_full(t_data *data)
{
    int i; 
    
    i=0;
    if(data->nbr_must_eat == -1)
        return(0);
    while(i < data->nbr_philos)
    {
        pthread_mutex_lock(&data->philos[i].meal_mutex);
        if(data->philos[i].meals_eaten < data->nbr_must_eat)
        {
            pthread_mutex_unlock(&data->philos[i].meal_mutex);
            return(0);
        }
        pthread_mutex_unlock(&data->philos[i].meal_mutex);
        i++;
    }
    return(1);
}
// Si must_eat == -1 significa que no hay límite, devolvemos 0 directamente. Si algún filósofo ha comido menos de must_eat veces, devolvemos 0. Solo devolvemos 1 si TODOS han comido suficiente.

static void set_simulation_over(t_data *data)
{
    pthread_mutex_lock(&data->death_mutex);
    data->simulation_over=1;
    pthread_mutex_unlock(&data->death_mutex);
}

void *monitor_routine(void *arg)
{
    t_data *data; 
    int i;
    
    data = (t_data *)arg; //???¿¿¿
    while(1)
    {
        i=0;
        while (i < data->nbr_philos)
        {
            if(philo_died(&data->philos[i]))
            {
                pthread_mutex_lock(&data->print_mutex);
                printf("%ld %d died\n", get_time_ms() - data->start_time, data->philos[i].philo_id);
                pthread_mutex_unlock(&data->print_mutex);
                set_simulation_over(data);
                return(NULL);
            }
            i++;
        }
        if(all_philos_full(data))
        {
            set_simulation_over(data);
            return(NULL);
        }
        usleep(500); //El usleep(500) al final del bucle evita que el monitor consuma el 100% de la CPU comprobando sin parar.
    }
    return(NULL);
}

=======
static int	philo_died(t_philo *philo)
{
	long	time_since_last_meal;

	pthread_mutex_lock(&philo->meal_mutex);
	time_since_last_meal = get_time_ms() - philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (time_since_last_meal > philo->data->time_to_die)
		return (1);
	return (0);
}
// Necesita el meal_mutex porque last_meal_time la escribe el filósofo 
// en philo_eat() y la lee el monitor aquí — acceso concurrente → mutex obligatorio.

static int	all_philos_full(t_data *data)
{
	int	i;

	i = 0;
	if (data->nbr_must_eat == -1)
		return (0);
	while (i < data->nbr_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_mutex);
		if (data->philos[i].meals_eaten < data->nbr_must_eat)
		{
			pthread_mutex_unlock(&data->philos[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&data->philos[i].meal_mutex);
		i++;
	}
	return (1);
}
// Si must_eat == -1 significa que no hay límite,
// devolvemos 0 directamente. Si algún filósofo ha comido menos de must_eat veces,
// devolvemos 0. Solo devolvemos 1 si TODOS han comido suficiente.

static void	set_simulation_over(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_over = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg; //???¿¿¿
	while (1)
	{
		i = 0;
		while (i < data->nbr_philos)
		{
			if (philo_died(&data->philos[i]))
			{
				pthread_mutex_lock(&data->print_mutex);
				printf("%ld %d died\n", get_time_ms() - data->start_time,
					data->philos[i].philo_id);
				pthread_mutex_unlock(&data->print_mutex);
				set_simulation_over(data);
				return (NULL);
			}
			i++;
		}
		if (all_philos_full(data))
		{
			set_simulation_over(data);
			return (NULL);
		}
		usleep(500);
			// El usleep(500) al final del bucle evita que el monitor consuma 
            // el 100% de la CPU comprobando sin parar.
	}
	return (NULL);
}
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
