/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:05:30 by marvin            #+#    #+#             */
/*   Updated: 2025/07/22 15:18:40 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
    if(s1 == NULL || s2 == NULL || n <= 0)
        return(0);
    while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	const char	s1[] = "julia";
	const char	s2[] = "juliaaaa";

	printf("%d\n", strncmp(s1, s2, 6));
	printf("%d", ft_strncmp(s1, s2, 6));
	return (0);
}
*/
