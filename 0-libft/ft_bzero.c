/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:21:05 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/28 17:27:18 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
}

/*
int	main(void)
{
	char	s[50] = "hola";

	ft_bzero (s + 2, 2);
	printf("Cadena modificada %s\n", s);
	return (0);
}
*/
