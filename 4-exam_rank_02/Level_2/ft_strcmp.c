/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/


int    ft_strcmp(char *s1, char *s2)
{
    int i; 

    i = 0; 
    while(s1[i] || s2[i])
    {
        if(s1[i] != s2[i])
            return(s1[i] - s2[i]);
    i++;
    }
    return(0);
}
/*
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc == 3)
    {
        printf("Resultado original: %d\n", strcmp(argv[1], argv[2]));
        printf("Resultado ft_strcmp: %d\n", ft_strcmp(argv[1], argv[2]));
    }
    return(0);
}
*/