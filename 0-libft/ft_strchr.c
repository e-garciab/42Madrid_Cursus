/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:04:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/22 12:57:48 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Se utilizan para buscar caracteres en cadenas de texto. Encuentra la primera ocurrencia de un carácter en una cadena.
// Devuelve un puntero a la primera aparición del carácter en la cadena, o NULL si el carácter no se encuentra.

    
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if (s[i] == c)
		// despues de salir del bucle while estamos al final de la cadena e i está en la posicion de '\0'. Si el caracter buscado es '\0' entra en este if y devuelve un puntero a esa posición ('\0)
		return ((char *)&s[i]);
	return (NULL);
}

int	main(void)
{
	const char s[] = "hola mundo";
	printf("%p\n", strchr(s, 'o'));
	printf("%p\n", ft_strchr(s, 'o'));
	return (0);
}