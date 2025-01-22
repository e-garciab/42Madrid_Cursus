/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:24:22 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/21 16:28:13 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c  - 32); 
	else
		return (c);
}

#include <ctype.h> 
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'n';
	printf("%c\n", toupper(c));
	printf("%c", ft_toupper(c));
	return (0);
}
