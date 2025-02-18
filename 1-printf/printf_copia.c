/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_copia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:15:28 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/18 14:17:56 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
// #include <stdarg.h>
// #include <unistd.h>

// int	ft_printf(char const *str, ...)
// {
// 	va_list args; // Declara una lista de argumentos variables.
// 	int i;
// 	int count;

// 	i = 0;
// 	count = 0;
// 	va_start(args, str); // inicia la lista de argumentos,
// 		//tomando str como el último argumento fijo.
// 							// Después de esto,
// 								//args nos permitirá acceder a los argumentos adicionales.
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '%')
// 		{
// 			i++;
// 			if (str[i] == '%')
// 				count += ft_print_char('%');
// 			if (str[i] == 'c')
// 				count += ft_print_char(va_arg(args, int));
// 			if (str[i] == 's')
// 				count += ft_print_str(va_arg(args, char *));
// 			if (str[i] == 'd')
// 				count += ft_print_nbr(va_arg(args, int));
// 			if (str[i] == 'i')
// 				count += ft_print_nbr(va_arg(args, int));
// 			if (str[i] == 'u')
// 				count += ft_print_unsigned_nbr(va_arg(args, unsigned int));
// 			if (str[i] == 'x')
// 				count += ft_print_hex(va_arg(args, int), 1);
// 			if (str[i] == 'X')
// 				count += ft_print_hex(va_arg(args, int), 0);
// 			if (str[i] == 'p')
// 				count += ft_print_ptr(va_arg(args, void *));
// 		}
// 		else
// 		{
// 			write(1, &str[i], 1);
// 			count++;
// 		}
// 		i++;
// 	}
// 	va_end(args);
// 	return (count);
// }