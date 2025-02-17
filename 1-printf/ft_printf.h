/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:09:48 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/17 14:56:35 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <bsd/string.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(char const *str, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unsigned_nbr (unsigned int n);

#endif /*FT_PRINTF_H*/