/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:43:47 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/24 10:51:15 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	char	sign;
	char	result;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		sign = '-';
		write(1, &sign, 1);
		n = -n;
		i++;
	}
	if (n > 9)
		i += ft_print_nbr(n / 10);
	result = (n % 10) + '0';
	write(1, &result, 1);
	i++;
	return (i);
}
