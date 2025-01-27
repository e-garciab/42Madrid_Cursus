/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:31:07 by marvin            #+#    #+#             */
/*   Updated: 2025/01/27 17:31:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char   *d;
    const unsigned char *s;
    size_t  i;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    
    if(s < d && d < s + n) // esto verificasi el bloque de memoria de destino esta dentro del bloque de memoria de origen. Si es verdadero, hay superposicion y hay qu copiar de atrás a adelante.
    {
        i = n; // i apunta justo despues del ultimo byte que queremos copiar 
        while (i > 0)
        {
            i--;
            d[i] = s[i];

        }
    }
    else
    { 
        i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}
*/

int main(void)
{
    char src1[50] = "Hello, World";
    //char dest1[20];
    size_t  n = 6;

    //char src2[20] = "hola mundo";
    //char dest2[20];

    memmove (src1 + 7, src1 + 5, n);
    printf("%s\n", src1);

    /*ft_memmove (dest2, src2, n);
    printf("%s\n", dest2);

    return (0);*/
}