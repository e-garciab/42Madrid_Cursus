#include "1-printf/ft_printf.h"
#include <stdio.h>

void test_char();
void test_str();
void test_putnbr();
void test_putunbr();
void test_putnbr_hex();
void test_putnbr_hex2();
void test_putaddr();

int main()
{
	test_char();
	test_str();
	test_putnbr();
	test_putunbr();
	test_putnbr_hex();
	test_putnbr_hex2();
	test_putaddr();

	return 0;
}

void test_char()
{
	int ret_og;
	int ret_copy;
	int test_number = 0;
	printf("\n----- TEST CHAR (%%c) -----\n");

	ret_og = printf("%c\n", 'a');
	ret_copy = ft_printf("%c\n", 'a');
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	

	char c = 'b';
	ret_og = printf("%c\n", c);
	ret_copy = ft_printf("%c\n", c);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	

	c = '\0';
	ret_og = printf("null char <%c>\n", c);
	ret_copy = ft_printf("null char <%c>\n", c);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	

	ret_og = printf("%c%c%c%c\n", 'd', 'e', '8', '\n');
	ret_copy = ft_printf("%c%c%c%c\n", 'd', 'e', '8', '\n');
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	
	ret_og = printf("%c\n", 94); // ^
	ret_copy = ft_printf("%c\n", 94);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	
	ret_og = printf("DEL <%c>\n", 127); // DEL
	ret_copy = ft_printf("DEL <%c>\n", 127); // DEL
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	

	ret_og = printf("extended char <%c>\n", 128); // idk
	ret_copy = ft_printf("extended char <%c>\n", 128); // idk
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	
	printf("\n----- END TEST CHAR (%%c) -----\n");
}

void test_str()
{
	int ret_og;
	int ret_copy;
	int test_number = 0;
	char *str;
	printf("\n----- TEST STR (%%s) -----\n");

	// normal strs
	ret_og = printf("%s\n", "'a'");
	ret_copy = ft_printf("%s\n", "'a'");
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	str = "Hola mundo :)";
	ret_og = printf("%s\n", str);
	ret_copy = ft_printf("%s\n", str);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// NULL as str
	str = NULL;
	ret_og = printf("null str %s\n", str);
	ret_copy = ft_printf("null str %s\n", str);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// str with only a null char
	str = "\0";
	ret_og = printf("null char <%s>\n", str);
	ret_copy = ft_printf("null char <%s>\n", str);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// empty str
	str = "";
	ret_og = printf("empty str <%s>\n", str);
	ret_copy = ft_printf("empty str <%s>\n", str);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// multiple strs
	ret_og = printf("%s%s%s%s%s\n", "multiple", " ", "strs", "\t", "concatenated");
	ret_copy = ft_printf("%s%s%s%s%s\n", "multiple", " ", "strs", "\t", "concatenated");
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	// multiple strs and NULL
	str = NULL;
	ret_og = printf("%s%s%s%s%s\n", "multiple", str, "strs", "\t", "concatenated");
	ret_copy = ft_printf("%s%s%s%s%s\n", "multiple", str, "strs", "\t", "concatenated");
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	printf("\n----- END TEST STR (%%s) -----\n");
}

void test_putnbr()
{
	int ret_og;
	int ret_copy;
	int test_number = 0;
	int nbr;
	printf("\n----- TEST D / I (%%d %%i) -----\n");

	// positive numbers %d
	ret_og = printf("%d\n", 0);
	ret_copy = ft_printf("%d\n", 0);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	nbr = 42;
	ret_og = printf("%d\n", nbr);
	ret_copy = ft_printf("%d\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// positive numbers %i
	ret_og = printf("%i\n", 0);
	ret_copy = ft_printf("%i\n", 0);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	nbr = 42;
	ret_og = printf("%i\n", nbr);
	ret_copy = ft_printf("%i\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// negative numbers
	nbr = -42;
	ret_og = printf("%d\n", nbr);
	ret_copy = ft_printf("%d\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	ret_og = printf("%i\n", nbr);
	ret_copy = ft_printf("%i\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	// multiple numbers
	ret_og = printf("%d %d %d\n", 1, 2, 3);
	ret_copy = ft_printf("%d %d %d\n", 1, 2, 3);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	ret_og = printf("%i %i %i\n", 1, 2, 3);
	ret_copy = ft_printf("%i %i %i\n", 1, 2, 3);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	// combine %d and %i
	ret_og = printf("%d %i %d %i %d %i\n", 1, 2, 3 , -4, -5, -66);
	ret_copy = ft_printf("%d %i %d %i %d %i\n", 1, 2, 3 , -4, -5, -66);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	// max int
	nbr = 2147483647;
	ret_og = printf("%d\n", nbr);
	ret_copy = ft_printf("%d\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	ret_og = printf("%i\n", nbr);
	ret_copy = ft_printf("%i\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// min int
	nbr = -2147483648;
	ret_og = printf("%d\n", nbr);
	ret_copy = ft_printf("%d\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	ret_og = printf("%i\n", nbr);
	ret_copy = ft_printf("%i\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;


//  * No deja compilar con las flags
	// overflow max int
	nbr = 2147483648;
	ret_og = printf("%d\n", nbr);
	ret_copy = ft_printf("%d\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	ret_og = printf("%i\n", nbr);
	ret_copy = ft_printf("%i\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// overflow min int
	nbr = -2147483649;
	ret_og = printf("%d\n", nbr);
	ret_copy = ft_printf("%d\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	ret_og = printf("%i\n", nbr);
	ret_copy = ft_printf("%i\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
 
	
	printf("\n----- END TEST D / I (%%d %%i) -----\n");
}

void test_putunbr()
{
	int ret_og;
	int ret_copy;
	int test_number = 0;
	unsigned int nbr;
	printf("\n----- TEST UNSIGNED (%%u) -----\n");

	// positive numbers %d
	ret_og = printf("%u\n", 0);
	ret_copy = ft_printf("%u\n", 0);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	nbr = 42;
	ret_og = printf("%u\n", nbr);
	ret_copy = ft_printf("%u\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// negative numbers
	nbr = -42;
	ret_og = printf("%u\n", nbr);
	ret_copy = ft_printf("%u\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	// multiple numbers
	ret_og = printf("%u %u %u\n", 1, 2095, 3456789);
	ret_copy = ft_printf("%u %u %u\n", 1, 2095, 3456789);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	// max unsigned int
	nbr = 4294967295;
	ret_og = printf("%u\n", nbr);
	ret_copy = ft_printf("%u\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// min int
	nbr = -2147483648;
	ret_og = printf("%u\n", nbr);
	ret_copy = ft_printf("%u\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;


//  * No deja compilar con las flags
	// overflow max unsigned int
	nbr = 4294967296;
	ret_og = printf("%u\n", nbr);
	ret_copy = ft_printf("%u\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// overflow min int
	nbr = -2147483649;
	ret_og = printf("%u\n", nbr);
	ret_copy = ft_printf("%u\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

 
	
	printf("\n----- END TEST UNSIGNED (%%u) -----\n");
}

void test_putnbr_hex()
{
	int ret_og;
	int ret_copy;
	int test_number = 0;
	unsigned int nbr = 0;
	printf("\n----- TEST HEXA (%%x) -----\n");

	// positive numbers %d
	ret_og = printf("%x\n", 0);
	ret_copy = ft_printf("%x\n", 0);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

	nbr = 42;
	ret_og = printf("%x\n", nbr);
	ret_copy = ft_printf("%x\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;
	
	// negative numbers
	nbr = -42;
	ret_og = printf("%x\n", nbr);
	ret_copy = ft_printf("%x\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

	// multiple numbers
	ret_og = printf("%x %x %x\n", 1, 2095, 3456789);
	ret_copy = ft_printf("%x %x %x\n", 1, 2095, 3456789);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

	// max unsigned int
	nbr = 4294967295;
	ret_og = printf("%x\n", nbr);
	ret_copy = ft_printf("%x\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;
	
	// min int
	nbr = -2147483648;
	ret_og = printf("%x\n", nbr);
	ret_copy = ft_printf("%x\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;


//  * No deja compilar con las flags
	// overflow max unsigned int
	nbr = 4294967296;
	ret_og = printf("%x\n", nbr);
	ret_copy = ft_printf("%x\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;
	
	// overflow min int
	nbr = -2147483649;
	ret_og = printf("%x\n", nbr);
	ret_copy = ft_printf("%x\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

 
	
	printf("\n----- END TEST HEXA (%%x) -----\n");
}

void test_putnbr_hex2()
{
	int ret_og;
	int ret_copy;
	int test_number = 0;
	unsigned int nbr = 0;
	printf("\n----- TEST HEXA MAJ (%%X) -----\n");

	// positive numbers %d
	ret_og = printf("%X\n", 0);
	ret_copy = ft_printf("%X\n", 0);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

	nbr = 42;
	ret_og = printf("%X\n", nbr);
	ret_copy = ft_printf("%X\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;
	
	// negative numbers
	nbr = -42;
	ret_og = printf("%X\n", nbr);
	ret_copy = ft_printf("%X\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

	// multiple numbers
	ret_og = printf("%X %X %X\n", 1, 2095, 3456789);
	ret_copy = ft_printf("%X %X %X\n", 1, 2095, 3456789);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

	// max unsigned int
	nbr = 4294967295;
	ret_og = printf("%X\n", nbr);
	ret_copy = ft_printf("%X\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;
	
	// min int
	nbr = -2147483648;
	ret_og = printf("%X\n", nbr);
	ret_copy = ft_printf("%X\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;


//  * No deja compilar con las flags
	// overflow max unsigned int
	nbr = 4294967296;
	ret_og = printf("%X\n", nbr);
	ret_copy = ft_printf("%X\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;
	
	// overflow min int
	nbr = -2147483649;
	ret_og = printf("%X\n", nbr);
	ret_copy = ft_printf("%X\n", nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [original num: %u expected: %i actual: %i]\n\n", test_number, nbr, ret_og, ret_copy);
	test_number++;

 
	
	printf("\n----- END TEST HEXA MAJ (%%X) -----\n");
}

void test_putaddr()
{
	int ret_og;
	int ret_copy;
	int test_number = 0;
	unsigned int nbr = 1;
	printf("\n----- TEST ADDR (%%p) -----\n");

	// address
	ret_og = printf("%p\n", &nbr);
	ret_copy = ft_printf("%p\n", &nbr);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;
	
	// null address
	ret_og = printf("%p\n", NULL);
	ret_copy = ft_printf("%p\n", NULL);
	if (ret_og != ret_copy)
		printf("ERROR test %i [expected: %i actual: %i]\n\n", test_number, ret_og, ret_copy);
	test_number++;

	printf("\n----- END TEST ADDR (%%p) -----\n");

}