/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 07:30:59 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 22:36:07 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief arse and validate command-line arguments.
/// Converts string arguments to long integers and checks for validity.
/// @param argc Number of command-line arguments.
/// @param argv Array of command-line argument strings.
/// @param args Array to store the parsed argument values.
/// @return Returns 1 if all arguments are valid, 0 otherwise.
static int	parse_args(int argc, char *argv[], long *args)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		exit_error("Error: invalid number of arguments\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &args[i - 1]))
		{
			exit_error("Error: invalid argument\n");
			return (0);
		}
		if (args[i - 1] <= 0)
		{
			exit_error("Error: values must be greater than 0\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/// @brief Initialize simulation parameters from parsed arguments.
/// Copies values from the parsed arguments array into the shared data
/// structure.
/// @param argc Number of command-line arguments.
/// @param args Array of parsed argument values.
/// @param data Pointer to the shared simulation data structure.
static void	init_args(int argc, long *args, t_data *data)
{
	data->nbr_philos = (int)args[0];
	data->time_to_die = args[1];
	data->time_to_eat = args[2];
	data->time_to_sleep = args[3];
	if (argc == 6)
		data->nbr_must_eat = (int)args[4];
	else
		data->nbr_must_eat = -1;
}

/// @brief Validate and initialize all simulation arguments.
/// @param argc Number of command-line arguments.
/// @param argv Array of command-line argument strings.
/// @param data Pointer to the shared simulation data structure.
/// @return Returns 1 if arguments are valid and initialization succeeds,
///  0 if argument parsing fails.
int	check_args(int argc, char *argv[], t_data *data)
{
	long	args[5];

	if (!parse_args(argc, argv, args))
		return (0);
	init_args(argc, args, data);
	return (1);
}
