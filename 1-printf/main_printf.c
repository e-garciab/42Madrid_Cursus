/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:12:24 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/18 15:02:46 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char			c;
	char			*str;
	char			z;
	int				n1;
	int				n2;
	int				n3;
	int				nb1;
	int				nb2;
	int				nb3;
	unsigned int	uns1;
	unsigned int	uns2;
	unsigned int	uns3;
	int				n;
	char			*str1;
	char			*str2;

	printf("%d\n", printf("Result: %%\n"));
	ft_printf("%d\n", ft_printf("Result: %%\n"));
	c = 'a';
	printf("%d\n", printf("Result: %c\n", c));
	ft_printf("%d\n", ft_printf("Result: %c\n", c));
	str = "hola mundo";
	printf("%d\n", printf("Result: %s\n", str));
	ft_printf("%d\n", ft_printf("Result: %s\n", str));
	z = 'b';
	printf("%d\n", printf("Result: %c %c %s\n", c, z, str));
	ft_printf("%d\n", ft_printf("Result: %c %c %s\n", c, z, str));
	n1 = 0;
	n2 = 2147483647;
	n3 = -2147483648;
	printf("%d\n", printf("Result: %d %d %d\n", n1, n2, n3));
	ft_printf("%d\n", ft_printf("Result: %d %d %d\n", n1, n2, n3));
	nb1 = 0;
	nb2 = 2147483647;
	nb3 = -2147483648;
	printf("%d\n", printf("Result: %i %i %i\n", nb1, nb2, nb3));
	ft_printf("%d\n", ft_printf("Result: %i %i %i\n", nb1, nb2, nb3));
	uns1 = -5;
	uns2 = 2147483647;
	uns3 = -2147483648;
	printf("%d\n", printf("Result: %u %u %u\n", uns1, uns2, uns3));
	ft_printf("%d\n", ft_printf("Result: %u %u %u\n", uns1, uns2, uns3));
	n = 0;
	printf("%d\n", printf("Result: %x %X\n", n, n));
	ft_printf("%d\n", ft_printf("Result: %x %X\n", n, n));
	str1 = "hola";
	str2 = "mundo";
	printf("%d\n", printf("Result: %p %p\n", str1, str2));
	ft_printf("%d\n", ft_printf("Result: %p %p\n", str1, str2));
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
