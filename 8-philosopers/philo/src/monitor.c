/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:49:51 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 21:58:50 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/// @brief Checks if a philosopher has exceeded time_to_die without eating.
/// Reads last_meal_time under meal_mutex to avoid data races with philo_eat().
/// @param philo Pointer to the philosopher to check.
/// @return 1 if the philosopher has died, 0 otherwise.
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

/// @brief Checks if all philosophers have eaten at least nbr_must_eat times.
/// Returns 0 immediately if nbr_must_eat is -1 (no limit set).
/// Reads meals_eaten under meal_mutex for each philosopher.
/// @param data Pointer to shared simulation data.
/// @return 1 if all philosophers are full, 0 otherwise.
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

static void	set_simulation_over(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_over = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

static int	check_death(t_data *data)
{
	int	i;

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
			return (1);
		}
		i++;
	}
	return (0);
}

/// @brief Monitor thread entry point.
/// Continuously checks for philosopher deaths and meal completion.
/// Runs every 0.1ms. Prints the death message before setting simulation_over
/// to ensure the message is not suppressed by print_state().
/// @param arg Pointer to t_data cast as void*.
/// @return Always NULL.
void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_death(data))
			return (NULL);
		if (all_philos_full(data))
		{
			set_simulation_over(data);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
