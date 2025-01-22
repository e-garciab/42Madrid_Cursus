/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:26:35 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/21 16:28:52 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

#include <ctype.h> 
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 80;
	printf("%d\n", tolower(c));
	printf("%d", ft_tolower(c));
	return (0);
}
