/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:57:33 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:15 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = '5';
	printf("%d\n", isdigit(c));
	printf("%d", ft_isdigit(c));
	return (0);
}

 /* Devuelve "verdadero" (un valor distinto de cero) si el carácter está entre 0 y 9.
Devuelve 0 en caso contrario */
