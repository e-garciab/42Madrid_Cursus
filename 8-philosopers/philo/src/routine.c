/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 09:01:13 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 21:56:50 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_think(t_philo *philo)
{
	long	think_time;

	think_time = philo->data->time_to_die - philo->data->time_to_eat
		- philo->data->time_to_sleep;
	if (think_time < 0)
		think_time = 0;
	think_time = think_time / 4;
	if (think_time > 0)
		ft_usleep(think_time, philo->data);
	print_state(philo, "is thinking");
}

static void	one_philo(t_philo *philo)
{
	print_state(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die, philo->data);
}

/// @brief Philosopher eating routine with deadlock prevention.
/// @param philo Pointer to the philosopher struct.
static void	philo_eat(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taken a fork");
	}
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_state(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ft_usleep(1, philo->data);
}

/// @brief Philosopher thread entry point.
/// Handles the special case of a single philosopher, then waits at the
/// synchronization barrier (ready flag) before entering the main loop.
/// Even-numbered philosophers delay by time_to_eat ms to prevent deadlock.
/// @param arg Pointer to the t_philo struct cast as void*.
/// @return Always NULL.
static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!is_ready(philo->data))
		continue ;
	if (philo->data->nbr_philos == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
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
		philo_think(philo);
	}
	return (NULL);
}

/// @brief Creates all philosopher threads and activates the start barrier.
/// Creates all threads first, then initialises start_time and last_meal_time
/// so that all philosophers share the same reference time. Sets ready=1 to
/// release all threads simultaneously.
/// @param data Pointer to shared simulation data.
/// @return 1 on success, 0 on pthread_create failure.
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
	return (1);
}
