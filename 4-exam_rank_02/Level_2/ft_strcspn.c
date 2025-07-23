/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;
    i=0;

    while(s[i])
    {
        j=0;
        while (reject[j])
        {
            if(s[i] == reject[j])
                return(i);    
            j++;
        }
    i++;
    }
    return(i);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    const char *str = "hola mundo";
    const char *reject = "aeiou";
    printf("Resultado original: %lu\n", strcspn(str, reject));
    printf("Resultado mi funcion: %lu\n", strcspn(str, reject));
    return(0);
}
*/