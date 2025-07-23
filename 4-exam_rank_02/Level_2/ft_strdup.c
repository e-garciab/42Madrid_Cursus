/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/

#include <stdlib.h>

static int ft_strlen(char *str)
{
    int i;
    i = 0;

    while(str[i])
        i++;
    return(i);
}

char    *ft_strdup(char *src)
{
    char *dest;
    int i;

    i=0;
    dest=malloc((ft_strlen(src) + 1) * sizeof(char));
    if(!dest)
        return (NULL);
    while(src[i])
    {    
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str= "hola mundo";
    printf("Resultado original: %s\n", strdup(str));
    printf("Resultado mi funcion: %s\n", ft_strdup(str));
    return(0);
}
*/
