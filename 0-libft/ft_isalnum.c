/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:24:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/16 17:35:28 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
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

	c = ' ';
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
	return (0);
}

/* Devuelve un valor distinto de cero (verdadero) si el carácter es alfanumérico,
 o 0 (falso) si no lo es */
