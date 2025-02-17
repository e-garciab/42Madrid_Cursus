/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:12:24 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/17 14:56:34 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	main(void)
{
	printf("%d\n", printf("Result: %%\n"));
	ft_printf("%d\n", ft_printf("Result: %%\n"));

	char	c;
	c = 'a';
	printf("%d\n", printf("Result: %c\n", c));
	ft_printf("%d\n", ft_printf("Result: %c\n", c));
	
	char	*str;
	str = "hola mundo";
	printf("%d\n", printf("Result: %s\n", str));
	ft_printf("%d\n", ft_printf("Result: %s\n", str));

	char	z;
	z = 'b';
	printf("%d\n", printf("Result: %c %c %s\n", c, z, str));
	ft_printf("%d\n", ft_printf("Result: %c %c %s\n", c, z, str));
	
	int	n1 = 0;
	int	n2 = 2147483647;
	int n3 = -2147483648;
	printf("%d\n", printf("Result: %d %d %d\n", n1, n2, n3));
	ft_printf("%d\n", ft_printf("Result: %d %d %d\n", n1, n2, n3));

	int	nb1 = 0;
	int	nb2 = 2147483647;
	int nb3 = -2147483648;
	printf("%d\n", printf("Result: %i %i %i\n", nb1, nb2, nb3));
	ft_printf("%d\n", ft_printf("Result: %i %i %i\n", nb1, nb2, nb3));

	unsigned int	uns1 = -42;
	unsigned int	uns2 = 2147483647;
	unsigned int	uns3 = -2147483648;
	printf("%d\n", printf("Result: %u %u %u\n", uns1, uns2, uns3));
	ft_printf("%d\n", ft_printf("Result: %u %u %u\n", uns1, uns2, uns3));

	return (0);
}

/*
	int	n;
	n = -34;
	unsigned int un = -34;

	printf("%d\n", n);
	printf("%i\n", n);
	printf("%u\n", n);
	printf("%u\n", un);
	

	// // result = ft_printf("%%");
	// // printf("%d\n", result);

	// char	c;
	// int		result;
	// char 	*str;
	
	
	// c = 'A';
	// unsigned long int i = (unsigned long int)  &str;
	// str = "Hola mundo";
	
	// result = ft_printf("%c\n%s\n",c, str);
	// printf("p de c %p\n", &str);
	// printf("p de i %lu\n", i);
	// printf("%d\n",result);

	// // int result;
	// // result = ft_printf("%s", str);
	// // printf("%d\n", result);

	
}
*/

