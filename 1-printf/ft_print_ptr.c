/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:30:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/18 14:01:39 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int	i;

	i = 0;
	write(1, "0x", 2);
	i += 2;
	i += ft_print_hex((unsigned long long)ptr, 1);
	return (i);
}
