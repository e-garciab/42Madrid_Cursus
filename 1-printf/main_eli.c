/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_eli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:12:24 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/24 14:03:48 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./1-printf/ft_printf.h"

int	main(void)
{
	char			c;
	char			*str;
	char			*vacio;
	char			z;
	int				n1;
	int				n2;
	int				n3;
	unsigned int	uns1;
	unsigned int	uns2;
	unsigned int	uns3;
	unsigned int	n;
	char			*str1;
	char			*str2;

	ft_printf("#1\n");
	printf("%d\n", printf("Result: %%\n"));
	ft_printf("%d\n", ft_printf("Result: %%\n"));
	ft_printf("\n");
	
	ft_printf("#2\n");
	c = 'a';
	printf("%d\n", printf("Result: %c\n", c));
	ft_printf("%d\n", ft_printf("Result: %c\n", c));
	ft_printf("\n");
	
	ft_printf("#3\n");
	str = "hola mundo";
	printf("%d\n", printf("Result: %s\n", str));
	ft_printf("%d\n", ft_printf("Result: %s\n", str));
	ft_printf("\n");
	
	ft_printf("#4\n");
	vacio = NULL;
	printf("%d\n", printf("Result: %s\n", vacio));
	ft_printf("%d\n", ft_printf("Result: %s\n", vacio));
	ft_printf("\n");
	
	ft_printf("#5\n");
	printf("%d\n", printf("Result: %p\n", str));
	ft_printf("%d\n", ft_printf("Result: %p\n", str));
	ft_printf("\n");
	
	ft_printf("#6\n");
	z = 'b';
	printf("%d\n", printf("Result: %c %c %s\n", c, z, str));
	ft_printf("%d\n", ft_printf("Result: %c %c %s\n", c, z, str));
	ft_printf("\n");
	
	ft_printf("#7\n");
	n1 = 0;
	n2 = 2147483647;
	n3 = -2147483648;
	printf("%d\n", printf("Result: %d %d %d\n", n1, n2, n3));
	ft_printf("%d\n", ft_printf("Result: %d %d %d\n", n1, n2, n3));
	ft_printf("\n");
	
	ft_printf("#8\n");
	printf("%d\n", printf("Result: %i %i %i\n", n1, n2, n3));
	ft_printf("%d\n", ft_printf("Result: %i %i %i\n", n1, n2, n3));
	ft_printf("\n");
	
	ft_printf("#9\n");
	uns1 = -5;
	uns2 = 2147483647;
	uns3 = -2147483648;
	printf("%d\n", printf("Result: %u %u %u\n", uns1, uns2, uns3));
	ft_printf("%d\n", ft_printf("Result: %u %u %u\n", uns1, uns2, uns3));
	ft_printf("\n");
	
	ft_printf("#10\n");
	n = -1;
	printf("%d\n", printf("Result: %x %X\n", n, n));
	ft_printf("%d\n", ft_printf("Result: %x %X\n", n, n));
	ft_printf("\n");
	
	ft_printf("#11\n");
	str1 = "hola";
	str2 = "mundo";
	printf("%d\n", printf("Result: %p %p\n", str1, str2));
	ft_printf("%d\n", ft_printf("Result: %p %p\n", str1, str2));
	ft_printf("\n");
	
	ft_printf("#12\n");
	long long LONG_MIN = 0;
	long long LONG_MAX = 0;
	printf("%d\n", printf("Result: %p %p ", LONG_MIN, LONG_MAX));
	ft_printf("%d\n", ft_printf("Result: %p %p ", LONG_MIN, LONG_MAX));
	ft_printf("\n");

	ft_printf("#13\n");
	printf("%d\n", printf("hola%"));
	ft_printf("%d\n", ft_printf("hola%"));
	ft_printf("\n");
	
	ft_printf("#14\n");
	printf("%d\n", printf("%mimi%"));
	ft_printf("%d\n", ft_printf("%mimi%"));
	ft_printf("\n");
	
	ft_printf("#15\n");
	printf("%d\n", printf("%skjg ", str));
	ft_printf("%d\n", ft_printf("%skjg ", str));
	ft_printf("\n");

	ft_printf("#16\n");
	printf("%d", ft_printf(NULL));
	printf("%d", printf(NULL));
	ft_printf("\n");

	ft_printf("#17\n");
	printf("%d\n", printf("Result: % hola"));
	ft_printf("%d\n", ft_printf("Result: % hola"));
	ft_printf("\n");
	
	ft_printf("#18\n");
	printf("%d\n", printf("%ka"));
	ft_printf("%d\n", ft_printf("%ka"));
	ft_printf("\n");
	
	ft_printf("#19\n");
	printf("%d\n", printf("%z"));
	ft_printf("%d\n", ft_printf("%z"));
	ft_printf("\n");

	ft_printf("#20\n");
	printf("%d\n", printf("%"));
	ft_printf("%d\n", ft_printf("%"));
	ft_printf("\n");

	ft_printf("#21\n");
	printf("%d\n", printf("ho%la"));
	ft_printf("%d\n", ft_printf("ho%la"));
	ft_printf("\n");

	ft_printf("#22\n");
	printf("%d\n", printf("%c %s %p %d %i %u %x %X %%", c, str, str1, n1, n, uns1, uns2, uns3));
	ft_printf("%d\n", ft_printf("%c %s %p %d %i %u %x %X %%", c, str, str1, n1, n, uns1, uns2, uns3));
	ft_printf("\n");
	
	ft_printf("#23\n");
	printf("%d\n", printf("%%c", str1));
	ft_printf("%d\n", ft_printf("%%c", str1));
	ft_printf("\n");

	return (0);
}