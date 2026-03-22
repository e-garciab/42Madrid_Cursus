/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:02:51 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 22:30:55 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Wait for all philosopher threads to finish.
/// Ensures that the main program waits until all philosopher routines 
/// have completed.
/// @param data Pointer to the shared simulation data structure.
/// @return Returns 1 if all threads are successfully joined,
/// 0 if any pthread_join fails.
static int	join_philos(t_data *data)
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

/// @brief Launches philosopher ans monitor threads. 
///  Ensures proper cleanup by joining all threads if any step fails.
/// @param data Pointer to the shared simulation data structure.
/// @return Returns 1 if the simulation runs successfully,
/// 0 if launching philosophers or creating the monitor thread fails.
static int	run_simulation(t_data *data)
{
	pthread_t	monitor;

	if (!launch_philos(data))
	{
		join_philos(data);
		return (0);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
	{
		join_philos(data);
		return (0);
	}
	pthread_join(monitor, NULL);
	join_philos(data);
	return (1);
}

/// @brief Parses command-line arguments, initializes simulation data,
/// runs the simulation, and cleans up resources at the end.
/// Exits with status 1 if argument checking or initialization fails.
/// @param argc Number of command-line arguments.
/// @param argv Array of command-line argument strings.
/// @return Returns 0 if the simulation completes successfully,
/// 1 if there is an error in arguments or initialization.
int	main(int argc, char *argv[])
{
	t_data	data;

	if (!check_args(argc, argv, &data))
		return (1);
	if (!init_data(&data))
	{
		cleanup(&data);
		return (1);
	}
	run_simulation(&data);
	cleanup(&data);
	return (0);
}
