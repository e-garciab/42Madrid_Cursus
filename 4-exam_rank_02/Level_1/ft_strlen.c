/* Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str); */

int ft_strlen(char *str)
{
    unsigned int    i;
    
    i=0;
    while(str[i] != '\0')
        i++;
    return (i);
}

/* 
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "Hola";
    printf("Mi Resultado: %d\n", ft_strlen(str));
    printf("Resultado Original: %d\n", ft_strlen(str));
    return(0);
}
*/