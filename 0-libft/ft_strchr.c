/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:04:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/21 18:32:49 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (*s);
		else
			i++;
	}
	return (NULL);
}



int	main(void)
{
	const char str[] = "Hola mundo";
	printf("%s\n", strchr(str, 'm'));
	printf("%s\n", ft_strchr(str, 'm'));
	return (0);
}