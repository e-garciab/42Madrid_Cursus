/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:30:56 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/13 15:06:56 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "stdio.h"

void ft_free_split(char **split)
{
	int i;
	i=0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int ft_is_valid_number(char *str)
{
    int i;

    i=0;
    if(!str || str[0] == '\0')
        return(0);
    if(str[i] == '+' || str[i] == '-')
        i++;
    if(str[i] == '\0')
        return(0);
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            return(0);
        i++;
    }
    return(1);
}

int ft_atoi_safe(char *str, int *out)
{
    int i;
    int sign;
    long result;

    i=0;
    sign=1;
    result=0;

    if(!str || str[0] == '\0')
		return(0);
	while ((str[i]) && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    if (str[i] == '+' || str[i] == '-')
		return (0);
	if(!ft_isdigit(str[i]))
		return(0);
    while (ft_isdigit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        if ((sign == 1 && result > INT_MAX) || (sign == -1 && result > (long)INT_MAX + 1))
        {
            write (2, "Error\n", 6);
            return(0);
        }
        i++;
    }
    
	*out = (int)(result * sign);
	return(1);
}

int	ft_has_duplicates(int *array, int len)
{
    int i;
    int j;

    i=0;
    while (i<len)
    {
        j = i + 1;
        while (j<len)
        {
            if (array[i] == array[j])
                return(1);
            j++;
        }
        i++;
    }
    return(0);
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

char **get_args(int argc, char *argv[], int *total_args)
{
	char **args;
	char **split;
	int i;
	int j;
	int k;
	int count;

	i=1;
	j=0;
	count=0;
	*total_args = ft_count_total_args(argc, argv);
	args = malloc((*total_args + 1) * sizeof(char *));
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
			args[j] = ft_strdup(split[k]);
			j++;
			k++;
		}
		ft_free_split(split);
		i++;
	}
	args[j] = NULL;
	return(args);
}

int *parse_args(int argc, char *argv[], int *total_args)
{
	char **args;
	int *numbers;
	int i;
	int num;

	i=0;
	args = get_args(argc, argv, total_args);
	if(!args)
		return(write(2, "Error\n", 6), NULL);
	numbers=malloc((*total_args + 1) * (sizeof(int)));
	if(!numbers)
		return(NULL);	
	while(i < *total_args)
	{
		if(!ft_is_valid_number(args[i]) || !ft_atoi_safe(args[i], &num))
		{
			write(2, "Error\n", 6);
			ft_free_split(args);
			free(numbers);
			return(NULL);
		}
		numbers[i] = num;
		i++;
	}
	if(ft_has_duplicates(numbers, *total_args))
	{
		write(2, "Error\n", 6);
		ft_free_split(args);
		free(numbers);
		return(NULL);
	}
	ft_free_split(args);
	return(numbers);	
}



int main(int argc, char *argv[])
{
	int *numbers;
	int i = 0;
	int total_args;
	
	if(argc<2)
		return(0);
	numbers = parse_args(argc, argv, &total_args);
	if(!numbers)
		return(1);
	//	solo para verificación
	i=0;
	while(i<total_args)
	{
		printf("%d\n", numbers[i]);
		i++;
	}
	free(numbers);
	return (0);
}