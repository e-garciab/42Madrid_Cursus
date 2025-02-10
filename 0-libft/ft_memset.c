/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:37:04 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/29 14:53:15 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief Fills the first n bytes of the memory area pointed to by s 
/// with the constant byte c
/// @param s pointer address to the memory area to be filled
/// @param c The value you want to fill the memory area with (converted 
/// to an unsigned char)
/// @param n The number of bytes to fill with the specified value.
/// @return pointer to the memory area that has been filled
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
	char s[50] = "hola";
	printf("Cadena original: %s\n", s);
	ft_memset(s+2, '*', 2);
	printf("Cadena modificada: %s\n", s);
	return (0);
}
*/
