/* 
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2); 
*/

// char *strcpy(char *dest, const char *src);

char *ft_strcpy(char *s1, char *s2)
{
    unsigned int    i;

    i=0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);
}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char src[] = "Hola";
    char dst[] = "";
    printf("Mi Resultado: %s\n", ft_strcpy(dst, src));
    printf("Resultado original: %s\n", strcpy(dst, src));
    return(0);
}
*/