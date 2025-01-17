/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:21:51 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/16 17:19:22 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
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

	c = '0';
	printf("%d\n", isalpha(c));
	printf("%d", ft_isalpha(c));
	return (0);
}

/* Devuelve "verdadero" (un valor distinto de cero) si el carácter está entre A y Z o entre a y z. 
Devuelve 0 en caso contrario */
