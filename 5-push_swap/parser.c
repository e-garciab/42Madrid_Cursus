/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:03:49 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/02 12:01:04 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_total_args(int argc, char *argv[])
{
	char	**split;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (count);
}
static int	normalize_args(int argc, char *argv[], char **args)
		// Convierte todos los argumentos (incluso si vienen agrupados como string con espacios) en un array plano de strings (args)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		k = 0;
		while (split[k])
		{
			args[j] = ft_strdup(split[k]);
			j++;
			k++;
		}
		ft_free_split(split);
		i++;
	}
	args[j] = NULL;
	return (1);
}

static char	**create_args_array(int argc, char *argv[], int total_args)
		// Reserva memoria para ese array plano de strings (args) y lo llena usando ft_fill_args.
{
	char **args;

	args = malloc((total_args + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	if (!normalize_args(argc, argv, args))
	{
		free(args);
		return (NULL);
	}
	return (args);
}
static int	convert_args_to_ints(char **args, int *numbers, int total_args)
		// recorre el array de string,
		verifica que sea un numero válido y convierto cada string a int,
		guardandolo en el array numbers.
{
	int i;
	int num;

	i = 0;
	while (i < total_args)
	{
		if (!ft_is_valid_number(args[i]) || !ft_atoi_safe(args[i], &num))
		{
			write(2, "Error\n", 6);
			ft_free_split(args);
			free(numbers);
			return (0);
		}
		numbers[i] = num;
		i++;
	}
	ft_free_split(args);
	return (1);
}

int	*parse_args(int argc, char *argv[], int total_args)
		// orquesta todo el proceso y devuelve el array final de enteros
{
	char **args;
	int *numbers;

	args = create_args_array(argc, argv, total_args);
	if (!args)
		return (write(2, "Error\n", 6), NULL);
	numbers = malloc((total_args + 1) * (sizeof(int)));
	if (!numbers)
		return (NULL);
	if (!convert_args_to_ints(args, numbers, total_args))
		return (NULL);
	if (ft_has_duplicates(numbers, total_args))
	{
		write(2, "Error\n", 6);
		free(numbers);
		return (NULL);
	}
	return (numbers);
}
