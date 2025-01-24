/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:47:19 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/24 11:47:26 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include<stdio.h>

// convert a string to an integer. Converts the initial portion of the string
// pointed to by nptr to int. 
// Returns the converted value or 0 on error.


int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] != '\0') && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
        
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}


int	main(void)
{
	const char nptr[] = "  -1234abc";
    int num = ft_atoi(nptr);
    printf("%d", num);
	return (0);
}