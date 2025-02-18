/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:12:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/18 14:02:00 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long n, int flag)
{
	char	*str;
	int		i;

	if (flag == 1)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	i = 0;
	if (n > 15)
		i += ft_print_hex(n / 16, flag);
	write(1, &str[n % 16], 1);
	i++;
	return (i);
}
