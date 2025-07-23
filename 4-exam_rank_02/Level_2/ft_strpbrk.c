/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

*/

// OPCION 1: CON INDICES
char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i=0;
    while (s1[i])
    {
        j=0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return((char *)&s1[i]);
            j++;        
       }
    i++;
    }
    return(0);
}

// OPCION 2: CON PUNTEROS
/*
char	*ft_strpbrk(const char *s1, const char *s2)
{
    const char *p1 = s1;
    const char *p2;

    while(*p1)
    {
        p2=s2;
        while(*p2)
        {
            if(*p1 == *p2)
                return((char *)p1);
            p2++;
        }
        p1++;
    }
    return(0);
}
*/

 #include <string.h>
 #include <stdio.h>

 int main(void)
 {
    char *str = "hola mundo";
    char *accept = "aeiou";

    printf("Resultado original: %s\n", strpbrk(str,accept));
    printf("Resultado mi funcion: %s\n", ft_strpbrk(str,accept));
    return(0);
 }