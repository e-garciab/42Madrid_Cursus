/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int		max(int* tab, unsigned int len)
{
    unsigned int i;
    int result;

    i=0;
    result=0;
    if(len>0)
    {
        while (i < len)
        {
            if(tab[i] > result)
                result = tab[i];
            i++;
        }
        return(result);
    }    
    return(0);
}


#include<stdio.h>

int main(void)
{
    int tab[] = {3,6,9,1,8};
    int len =5;
    printf("Resultado %d\n", max(tab,len));
    return(0);
}