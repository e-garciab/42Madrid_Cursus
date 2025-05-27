/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
    int temp; 
    temp = *a;
    *a = *b;
    *b = temp;
}
/*
#include <stdio.h>

int main(void)
{
    int a;
    int b;

    a= 1;
    b=2;
    printf("Valor original de a: %d\nValor original de b: %d\n", a, b);
    ft_swap(&a,&b);
    printf("Valor cambiado de a: %d\nValor cambiado de b:%d\n", a, b);
}
    */