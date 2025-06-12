/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:30:56 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/12 14:41:14 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "stdio.h"

void ft_free_split(char **str)
{
	int i;
	i=0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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

char **get_args(int argc, char *argv[])
{
	char **args;
	char **split;
	int i;
	int j;
	int k;
	int total_args;

	i=1;
	j=0;
	total_args = ft_count_total_args(argc, argv);
	args = malloc((total_args + 1) * sizeof(char *));
	if(!args)
		return(NULL);
	while(i<argc)
	{
		split = ft_split(argv[i], ' ');
		if(!split)
			return(NULL);
		k=0;
		while(split[k])
		{
			args[j] = split[k];
			j++;
			k++;
		}
		free(split);
		i++;
	}
	args[j] = NULL;
	return(args);
}

int main(int argc, char *argv[])
{
	char **args;
	int i = 0;
	
	if(argc<2)
		return(0);
	args = get_args(argc, argv);
	if(!args)
	{
		write(2, "Error\n", 6);
		return(1);
	}
	// solo para verificación
	while(args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
	return (0);
}