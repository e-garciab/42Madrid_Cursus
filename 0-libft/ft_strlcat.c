/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:16:24 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/22 11:23:57 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;


	j = 0;
	len = ft_strlen(dst);
	i = len;

	if (size < len)
		return (size + ft_strlen(src));
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (len + ft_strlen(src));
}


int	main(void)
{
	char dst[30] = "hola";
	const char src[] = " mundo";
	size_t size = 10;

	printf("%lu\n", ft_strlcat(dst, src, size));
	printf("%s\n", dst);
	return (0);
}
