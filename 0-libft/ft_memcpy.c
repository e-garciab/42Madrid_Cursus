/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:44:43 by marvin            #+#    #+#             */
/*   Updated: 2025/01/27 16:44:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

//copies n bytes from memory area src to memory area dest.
//The memory areas must not overlap. 
// The memcpy() function returns a pointer to dest.

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    // dado que void* es un puntero genérico, primero necesitamos convertir esos punteros 
    //a un tipo específico para poder trabajar con ellos. Los convierto a unsigned char* 
    //ya que unsigned char tiene un tamaño de 1 byte y nos permite trabajar con los datos a nivel de byte.
        
    unsigned char   *d;
    const unsigned char *s;
    size_t  i;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    i = 0;

    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}

int main(void)
{
    char src[20] = "hola mundo";
    char dest[20];
    size_t  n = 6;

    //printf("%p\n", memcpy (dest, src, n));
    //printf("%p\n", ft_memcpy (dest, src, n));
    ft_memcpy (dest, src, n);
    printf("%s\n", dest);

    return (0);
}