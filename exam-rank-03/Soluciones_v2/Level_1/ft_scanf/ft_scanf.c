#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/*
 * match_space: Consumes leading whitespace characters from the input stream.
 * @f: The file stream to read from (e.g., stdin).
 * Returns: 0 on success (whitespace consumed or no whitespace found),
 * -1 if EOF or an error occurs while reading.
*/
 int match_space(FILE *f) //salta espacios en el input
{
    int c;
    c=fgetc(f);
    if(c == EOF)
        return(-1);
    while(isspace(c))
        c = fgetc(f);
    unget(c,f);
    return(0);
}

/*
 * match_char: Reads a single character from the input stream and compares it
 * to a specified character.
 * @f: The file stream to read from.
 * @c: The character to match.
 * Returns: 1 if the character matches and is consumed,
 * 0 if the character does not match (and is put back),
 * -1 if EOF or an error occurs.
 */
int match_char(FILE *f, char c) //verifica que el carácter del input coincide con el format
{
        // You may insert code here
    return (0);
}

int scan_char(FILE *f, va_list ap) //lee un carácter y lo guarda
{
        // You may insert code here
    return (0);
}

int scan_int(FILE *f, va_list ap) // lee un entero y lo guarda
{
        // You may insert code here
    return (0);
}

int scan_string(FILE *f, va_list ap) // lee una palabra y la guarda
{
        // You may insert code here
    return (0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;
    va_start(ap,format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}