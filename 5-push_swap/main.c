/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:30:56 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/12 18:04:45 by egarcia2         ###   ########.fr       */
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

int ft_atoi_safe(char *str)
{
    int i;
    int sign;
    long result;

    i=0;
    sign=1;
    result=0;

    if(!str || str[0] = '\0')
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
    while ((str[i]) >= '0' && (str[i]) <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if ((sign == 1 && result > 2147483647) || (sign == -1 && result < -2147483648))
        {
            write (2, "Error\n", 6);
            return(0);
        }
        i++;
    }
    return(result * sign);
}

int	ft_has_duplicates(char **args)
{
    int i;
    int j;

    i=0;
    while (args[i])
    {
        j = i + 1;
        while (args[j])
        {
            if ((ft_atoi_safe(args[i])) == (ft_atoi_safe(args[j])))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
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
	while(args[i])
	{
		if(!ft_is_valid_number(args[i]))
		{
			write(2, "Error\n", 6);
			return(1);
		}
		i++;
	}
	if(ft_has_duplicates(args))
	{
		write(2, "Error\n", 6);
		return(1);
	}
	//	solo para verificación
	i=0;
	while(args[i])
	{
		printf("%s\n", args[i]);
		i++;
	}
	return (0);
}