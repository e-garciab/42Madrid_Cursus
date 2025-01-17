/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:40:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/01/17 12:25:29 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h> */

int	ft_isalpha(int c); OK
int	ft_isdigit(int c); OK
int	ft_isalnum(int c); OK
int	ft_isascii(int c); duda-sale siempre 1
int	ft_isprint(int c); OK

/* #include <string.h> */

size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s. size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* #include <ctype.h> */
int	ft_toupper(int c); OK
int	ft_tolower(int c); OK

/* #include <string.h> */

char	ft_strchr(const char *s, int c);
char	ft_strrchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* #include <stdlib.h> */
int	ft_atoi(const char *nptr);

