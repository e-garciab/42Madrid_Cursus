/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:01:13 by egarcia2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/15 21:36:01 by egarcia2         ###   ########.fr       */
=======
/*   Updated: 2026/03/17 20:41:12 by egarcia2         ###   ########.fr       */
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

<<<<<<< HEAD
static void one_philo(t_philo *philo)
{
    print_state(philo, "has taken a fork");
    ft_usleep(philo->data->time_to_die, philo->data);   
}

static void philo_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    print_state(philo, "has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    print_state(philo, "has taken a fork");
    print_state(philo, "is eating");
    pthread_mutex_lock(&philo->meal_mutex);
    philo->last_meal_time=get_time_ms();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->meal_mutex);
    ft_usleep(philo->data->time_to_eat, philo->data);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}

void *routine(void *arg)
{
    t_philo *philo; 
    
    philo = (t_philo *)arg; //¿¿¿????
    if(philo->data->nbr_philos == 1)
    {
        one_philo(philo);
        return(NULL);
    }
    if(philo->philo_id %2 == 0) //si es un nº de philo par
        ft_usleep(1, philo->data);
    while(!is_simulation_over(philo->data))
    {
        philo_eat(philo);
        if(is_simulation_over(philo->data))
            break; 
        print_state(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep, philo->data);
        if(is_simulation_over(philo->data))
            break;
        print_state(philo, "is thinking");
    }
    return(NULL);
}

int launch_philos(t_data *data)
{
    int i; 

    i=0;
    while(i < data->nbr_philos)
    {
        if(pthread_create(&data->philos[i].thread, NULL, routine, &data ->philos[i]) != 0)
            return (0);
        i++;
    }
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



=======
static void	one_philo(t_philo *philo)
{
	print_state(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die, philo->data);
}

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_state(philo, "has taken a fork");
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg; //¿¿¿????
	if (philo->data->nbr_philos == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0) // si es un nº de philo par
		ft_usleep(1, philo->data);
	while (!is_simulation_over(philo->data))
	{
		philo_eat(philo);
		if (is_simulation_over(philo->data))
			break ;
		print_state(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		if (is_simulation_over(philo->data))
			break ;
		print_state(philo, "is thinking");
	}
	return (NULL);
}

int	launch_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, routine,
				&data->philos[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	join_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
