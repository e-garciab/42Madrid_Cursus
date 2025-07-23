/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

int ft_atoi(const char *str)
{
    int i;
    int result;
    int sign;

    i = 0;
    result = 0;
    sign = 1;
    while(str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
        i++;
    if(str[i] == '-')
    {
        sign = -sign;
        i++;
    }
    if(str[i] == '-' || str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 +(str[i] -'0');
        i++;
    }
    return(result*sign);
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        printf("Resultado original: %d\n", atoi(argv[1]));
        printf("Resultado mi funcion: %d\n", ft_atoi(argv[1]));
    }
    return(0);
}