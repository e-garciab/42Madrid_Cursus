/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 07:30:59 by egarcia2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/14 08:53:09 by egarcia2         ###   ########.fr       */
=======
/*   Updated: 2026/03/17 20:41:07 by egarcia2         ###   ########.fr       */
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5    800     200 200 [5]
//      argv[1] argv[2] argv[3] ...
// 1) ensure they are numbers
// 2) ensure they are not > INT MAX
// 3) timestamps > 60

<<<<<<< HEAD

static int parse_args(int argc, char *argv[], long *args)
{
	int i;
	if(argc < 5 || argc > 6)
	{
		exit_error("Error: invalid number of arguments\n");
		return(0);
	}
	i=1;
	while (i < argc)
	{
		if(!ft_atoi_safe(argv[i], &args[i - 1]))
		{
			exit_error("Error: invalid argument\n");
			return(0);
		}
		if(args[i-1] < 0)
		{
			exit_error("Error: values must be greater than 0\n");
			return(0);
		}
		i++;
	}
	return(1);
}

static void init_args (int argc, long *args, t_data *data)
=======
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
		if (args[i - 1] < 0)
		{
			exit_error("Error: values must be greater than 0\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	init_args(int argc, long *args, t_data *data)
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
{
	data->nbr_philos = (int)args[0];
	data->time_to_die = args[1];
	data->time_to_eat = args[2];
	data->time_to_sleep = args[3];
<<<<<<< HEAD
	if(argc == 6)
		data->nbr_must_eat = (int)args[4];
	else	
    	data->nbr_must_eat = -1;
	
}

int check_args (int argc, char *argv[], t_data *data)
{
	long	args[5];

	if(!parse_args(argc, argv, args))
		return(0);
	init_args(argc, args, data);
	return(1);
}

=======
	if (argc == 6)
		data->nbr_must_eat = (int)args[4];
	else
		data->nbr_must_eat = -1;
}

int	check_args(int argc, char *argv[], t_data *data)
{
	long	args[5];

	if (!parse_args(argc, argv, args))
		return (0);
	init_args(argc, args, data);
	return (1);
}
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
