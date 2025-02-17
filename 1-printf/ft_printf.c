/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:15:28 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/17 14:56:36 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>




// int	print_ptr()
// int	print_decimal()
// int	print_int()
// int	print_unsigned_decimal()
// int	print_hex_lower()
// int	print_hex_upper()



int	ft_printf(char const *str, ...)
{
	va_list args; //Declara una lista de argumentos variables.
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	va_start(args, str); //inicia la lista de argumentos, tomando str como el último argumento fijo. 
						 // Después de esto, args nos permitirá acceder a los argumentos adicionales.
	while (str[i] != '\0')
	{	
		if (str[i] == '%')
		{	
			if ((str[i + 1]) == '%')
			{	
				count += ft_print_char('%');
				i++;
			}			
			if ((str[i + 1]) == 'c')
			{	
				count += ft_print_char(va_arg(args, int));
				i++;
			}
			if ((str[i + 1]) == 's')
			{	
				count += ft_print_str(va_arg(args, char *));
				i++;
			}
			if ((str[i + 1]) == 'd')
			{	
				count += ft_print_nbr(va_arg(args, int));
				i++;
			}
			if ((str[i + 1]) == 'i')
			{	
				count += ft_print_nbr(va_arg(args, int));
				i++;
			}
			if ((str[i + 1]) == 'u')
			{	
				count += ft_print_nbr(va_arg(args, unsigned int));
				i++;
			}
		}
		else
		{	
			write (1, &str[i], 1);
			count++;
		}
		i++;
	}			
	va_end(args);
	return(count);
	}
/*
int	main(void)
{
	//printf("Este es mi primer caracter %c\n", 'a');
	
	printf("%d\n",ft_printf("Este es mi primer caracter %c%c%c\n", 'a', 'b', 'c'));
	return (0);
}

*/

/*
int	sumatorio (int n, ...)
{
	va_list	vargs;
	int	i;
	int	ac;
	int	sig;

	i = 0;
	ac = 0;
	va_start (vargs, n);
	while (i < n)
	{	
		sig = va_arg(vargs, int);
		i++;
		ac += sig;
	}
	va_end(vargs);
return (ac);	
}

int	main()
{
	int total = sumatorio (3, 1, 2, 3);
	printf("Total: %d\n", total);
	return (0);
}

			if ((str[i] + 1) == 'c')
				ft_putchar_fd ((va_arg(args, char)), 1);
				// contar longitud de lo que ha escrito
				i++;	
		}
			else if ((str[i] + 1) == 's')
				ft_putstr_fd((va_arg(args, char*)), 1);
				
				i++;
			else if ((str[i] + 1) == 'i')
				c = va_arg(args, int);
				ft_putnbr_fd();
				i++;

*/