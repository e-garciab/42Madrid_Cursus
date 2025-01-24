/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:54:35 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/24 11:45:38 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <stdio.h>

// locates the first occurrence of the null-terminated string little in the 
// string big, where not more than len characters
// are searched. Only the first len characters are searched.
// Return value:
// If little is an empty string, big is returned;
// if little occurs nowhere in big, NULL is returned;
// otherwise a pointer to the first character of the first occurrence of little 
// is returned.

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	z;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (i <= len)
	{
		if (big[i] == little[j])
		{
			z = i;
			while (big[z++] == little[j] && little[j++] != '\0')
			{
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}


int	main(void)
{
	const char *big = "FoBBo Bar Baz";
	const char *little = "Bo";
	char *ptr;

	ptr = strnstr(big, little, 12);

	printf("%s\n", ptr);
	printf("%s\n", ft_strnstr(big, little, 12));
	return (0);
}
