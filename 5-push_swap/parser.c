/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:03:49 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/11 21:32:41 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int is_valid_number(char *str)
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

int	has_duplicates(int *arr, int size)
{
    int i;
    int j;

    i=0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

int ft_atoi_safe(char *str)
{
    int i;
    int sign;
    long result;

    i=0;
    sign=1;
    result=0;

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
    while ([str[i]] >= '0' && [str[i]] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (sign == 1 && result > 2147483647) || (sign = -1 && result < -2147483648)
        {
            write (2, "Error\n", 6);
            return(0);
        }
        i++;
    }
    return(result * sign);
}

