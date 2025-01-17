/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:13:06 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/17 12:16:00 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = '5';
	printf("%d\n", isprint(c));
	printf("%d", ft_isprint(c));
	return (0);
}
