/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:15:49 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 21:57:12 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Uses gettimeofday() to get seconds and microseconds since the 
///			Unix epoch and converts the result to milliseconds.
/// @return Returns the current time in milliseconds.
long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/// @brief Sleeps for the given number of milliseconds with precision.
/// @param ms Duration to sleep in milliseconds.
/// @param data Pointer to shared simulation data
void	ft_usleep(long ms, t_data *data)
{
	long	start;

	start = get_time_ms();
	while ((get_time_ms() - start) < ms)
	{
		if (is_simulation_over(data))
			break ;
		usleep(100);
	}
}

/// @brief Thread-safe check of whether the simulation has ended.
///			Reads simulation_over under death_mutex to prevent data races
///			between the monitor (writer) and philosopher (readers).
/// @param data Pointer to shared simulation data.
/// @return 1 if the simulation is over, 0 if still running.
int	is_simulation_over(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->death_mutex);
	result = data->simulation_over;
	pthread_mutex_unlock(&data->death_mutex);
	return (result);
}

/// @brief Prints a philosopher state change in the required format.
///		Acquires print_mutex before printing to prevent interleaved output.
///		Skips the print if the simulation has already ended.
/// @param philo Pointer to the philosopher.
/// @param state State string (e.g. "is eating", "is sleeping")
void	print_state(t_philo *philo, char *state)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!is_simulation_over(philo->data))
	{
		timestamp = get_time_ms() - philo->data->start_time;
		printf("%ld %d %s\n", timestamp, philo->philo_id, state);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	is_ready(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->ready_mutex);
	result = data->ready;
	pthread_mutex_unlock(&data->ready_mutex);
	return (result);
}
