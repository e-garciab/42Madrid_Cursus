/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:16:50 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/28 13:02:26 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)&str[i]);
		else
			i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	str[20] = "hola mundo";
	int			c = 'l';
	size_t		n = 4;
	char		*result = ft_memchr (str, c, n);

	printf ("%s\n", result);
	return (0);
}
*/
