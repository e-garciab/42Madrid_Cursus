/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:01:16 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/30 20:23:20 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0' && i < ft_strlen(s) && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
int	main(void)
{
	char const s[] = "hola";
	unsigned int start = 4294967295;
	size_t len = 0;                
	printf("%s\n", ft_substr(s, start, len));
	return (0);
}
*/

//s: La string desde la que crear la substring.
//start: el índice del caracter en ’s’ desde el que empezar la substring
//len:  La longitud máxima de la substring.