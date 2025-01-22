/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:20:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/21 12:26:52 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /*necesaria para usar el tipo de dato size_t*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <string.h>

int	main(void)
{
	const char	s[] = "Hello World!";

	printf("%lu\n", strlen(s));
	printf("%lu", ft_strlen(s));
	return (0);
}*/
