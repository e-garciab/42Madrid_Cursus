/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:03:49 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:42 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_count_total_args(int argc, char *argv[])
{
	char **split;
	int i;
	int j;
	int total_args;

	i= 1;
	total_args=0;
	while (i< argc)
	{
		split = ft_split (argv[i], ' ');
		if(!split)
			return(-1);
		j=0;
		while(split[j])
		{
			total_args++;
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return(total_args);
}

int ft_fill_args(int argc, char *argv[], char **args)
{
	char **split;
	int i;
	int j;
	int k;

	i=1;
	j=0;
	while(i<argc)
	{
		split = ft_split(argv[i], ' ');
		if(!split)
			return(0);
		k=0;
		while(split[k])
		{
			args[j] = ft_strdup(split[k]);
			j++;
			k++;
		}
		ft_free_split(split);
		i++;
	}
	args[j] = NULL;
	return(1);
}

char **get_args(int argc, char *argv[], int *total_args)
{
	char **args;

	*total_args = ft_count_total_args(argc, argv);
	args = malloc((*total_args + 1) * sizeof(char *));
	if(!args)
		return(NULL);
	if(!ft_fill_args(argc, argv, args))
	{
		free(args);
		return(NULL);
	}
	return(args);
}
int ft_fill_numbers_array(char **args, int *numbers, int total_args)
{
	int i;
	int num;

	i=0;
	while(i < total_args)
	{
		if(!ft_is_valid_number(args[i]) || !ft_atoi_safe(args[i], &num))
		{
			write(2, "Error\n", 6);
			ft_free_split(args);
			free(numbers);
			return(0);
		}
		numbers[i] = num;
		i++;
	}
	ft_free_split(args);
	return(1);
}

int *parse_args(int argc, char *argv[], int *total_args)
{
	char **args;
	int *numbers;

	args = get_args(argc, argv, total_args);
	if(!args)
		return(write(2, "Error\n", 6), NULL);
	numbers=malloc((*total_args + 1) * (sizeof(int)));
	if(!numbers)
		return(NULL);
	if(!ft_fill_numbers_array(args, numbers, *total_args))
		return(NULL);
	if(ft_has_duplicates(numbers, *total_args))
	{
		write(2, "Error\n", 6);
		free(numbers);
		return(NULL);
	}
	return(numbers);	
}

