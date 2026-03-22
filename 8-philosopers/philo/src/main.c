/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:02:51 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 21:58:33 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
