/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:50:49 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/24 10:52:05 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_nbr(unsigned int n)
{
	char	result;
	int		i;

	i = 0;
	if (n > 9)
		i += ft_print_nbr(n / 10);
	result = (n % 10) + '0';
	write(1, &result, 1);
	i++;
	return (i);
}
