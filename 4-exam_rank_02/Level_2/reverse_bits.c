/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100

*/
  unsigned char	reverse_bits(unsigned char octet)
  {
    int i=8;
    unsigned char bit = 0;

    while (i > 0)
    {
      bit = (bit << 1) | (octet & 1);
      octet = octet >> 1;
      i--;
    }
    return(bit);
  }

#include <stdio.h>
int	main(void)
{
	unsigned char bit = 0;
	// by changing the number on the next line, you change
	// the bits that are sent to the reverse_bits function
	// 5 => 0000 0101, the result should be 1010 0000
	unsigned char res = reverse_bits((unsigned char)5);

	int i = 8;
	while (i--)
	{
		bit = (res >> i & 1) + 48;
		printf("%c", bit);
	}
}