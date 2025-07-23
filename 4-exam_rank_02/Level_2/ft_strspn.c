/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/

#include <stddef.h>

size_t ft_strspn(const char *s, const char *accept)
{
    int i; 
    int j;

    i=0;
    j=0;
    while (s[i] && accept[j] && (s[i] == accept[j]))
    {
        j++;
        i++;
    }
    return (i);
}

#include <string.h>
#include <stdio.h>

int main(void)
{
    char *str = "hola mundo";
    char *accept = "hola";
    
    printf("Resultado original: %ld\n", strspn(str, accept));
    printf("Resultado mi funcion: %ld\n", ft_strspn(str, accept));
    return(0);
}