/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:05:30 by marvin            #+#    #+#             */
/*   Updated: 2025/01/24 17:05:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

// Compares the first n bytes of two strings s1 and s2. 
// It returns an integer less than, equal to, or greater than zero if s1 is found, 
// respectively, to be less than, to match, or be greater than s2.


int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && ((s1[i] != '\0') || (s2[i] != '\0')))
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}


int	main(void)
{
	const char	s1[] = "holacaracola";
	const char	s2[] = "hola";

	printf("%d\n", strncmp(s1, s2, 20));
	printf("%d", ft_strncmp(s1, s2, 20));
	return (0);
}