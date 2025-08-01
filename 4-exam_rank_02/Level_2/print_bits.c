/*Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit = 0;

    while (i > 0)
    {
        bit = (octet >> i & 1) + 48;
        write (1, &bit, 1);
        i--;
    }
}

int main(void)
{
    unsigned char octet = 2;
    print_bits(octet);
}