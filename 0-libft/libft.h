/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:40:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/28 18:54:40 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>

int		ft_isalpha(int c); /*OK*/
int		ft_isdigit(int c); /*OK*/
int		ft_isalnum(int c); /*OK*/
int		ft_isascii(int c); /*duda-sale siempre 1*/
int		ft_isprint(int c); /*OK*/
int		ft_toupper(int c); /*OK*/
int		ft_tolower(int c); /*OK*/
size_t	ft_strlen(const char *s); /*OK*/
void	*ft_memset(void *s, int c, size_t n); /*OK*/
void	ft_bzero(void *s, size_t n); /*DUDA, comprobar si funciona*/
void	*ft_memcpy(void *dest, const void *src, size_t n); /*OK*/
void	*ft_memmove(void *dest, const void *src, size_t n); /*OK*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size); /*OK*/
size_t	ft_strlcat(char *dst, const char *src, size_t size); /*OK*/
char	*ft_strchr(const char *s, int c); /*OK*/
char	*ft_strrchr(const char *s, int c); /*falta condición para cuando
 c es \0*/
int		ft_strncmp(const char *s1, const char *s2, size_t n); /*DUDA 
valor de retorno no igual a funcion original*/
void	*ft_memchr(const void *s, int c, size_t n); /*OK*/
int		ft_memcmp(const void *s1, const void *s2, size_t n); /*OK*/
char	*ft_strnstr(const char *big, const char *little, size_t len); /*OK*/
int		ft_atoi(const char *nptr);

#endif /*LIBFT_H*/
