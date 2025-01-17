/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:24:22 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/17 14:27:23 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}

#include <ctype.h> 
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 113;
	printf("%d\n", toupper(c));
	printf("%d", ft_toupper(c));
	return (0);
}
