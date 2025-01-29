/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:04:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/29 14:53:21 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	const char	s[] = "hola mundo";

	printf("%p\n", strchr(s, 'o'));
	printf("%p\n", ft_strchr(s, 'o'));
	return (0);
}
*/
