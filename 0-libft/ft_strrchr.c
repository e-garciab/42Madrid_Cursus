/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:35:21 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/22 13:37:56 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>


// Encuentra la última ocurrencia de un carácter en una cadena.
// Devuelve un puntero a la última aparición del carácter en la cadena, o NULL si el carácter no se encuentra.

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	
	i = 0;
	
	while (s[i] != '\0')
		i++;

	while (i >= 0) // inicialmente i es la longitud total del string y con este while lo muevo hasta que i = 0 (primera posicion del strring)
		if (s[i] == c)
			return ((char *)&s[i]);
		else
			i--;
	return (NULL);
}





int	main(void)
{
	const char s[] = "hola mundo";
	printf("%s\n", strrchr(s, 'w'));
	printf("%s\n", ft_strrchr(s, 'w'));
	return (0);
}
