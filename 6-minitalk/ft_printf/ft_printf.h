/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:09:48 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/24 11:09:57 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unsigned_nbr(unsigned int n);
int	ft_print_hex(unsigned long n, char flag);
int	ft_print_ptr(void *ptr);

#endif /*FT_PRINTF_H*/