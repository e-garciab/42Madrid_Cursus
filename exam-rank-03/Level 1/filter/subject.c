
Assignment name: filter
Expected files: filter.c
Allowed functions: read, write, strlen, memmem, memmove, malloc, calloc,
realloc, free, printf, fprintf, stdout, stderr, perror
--------------------------------------------------------------------------------

Write a program that will take one and only one argument.

Your program will then read from stdin and write all the content read in stdout
except that every occurrence of s must be replaced by '*' (as many as the length
of s). Your program will be tested with random buffer sizes, using a custom read
function. Therefore the buffer being set in your program will be filled with a
different number of chars each new call.


For example:

./filter bonjour
will behave in the same way as:
sed 's/bonjour/*******/g'

./filter abc
will behave in the same way as:
sed's/abc/***/g'

More generally your program must be the equivalent of the shell script filter.sh
present in this directory (you can compare your program with it).

In case of error during a read or a malloc, you must write "Error: " followed by
the error message in stderr and return 1.

If the program is called without arguments or with an empty argument or with multiple
arguments, it must return 1.

For example this should work:

$> echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e
***defaaa***de******d***$
$> echo 'ababcabababc' | ./filter ababc | cat -e
*****ab*****$
$>

NOTES:
memmem includes:
                #define _GNU_SOURCE
                            #include <string.h>

perror includes:
                #include <errno.h>

read includes:
                #include <fcntl.h>




/*
- Debes escribir un programa en C llamado filter.
- El programa recibe exactamente un argumento: una cadena s.
- El programa lee datos desde stdin (entrada estándar).
- El programa escribe en stdout (salida estándar) todo lo que ha leído, pero:
    - Cada vez que aparezca la cadena s en el texto, debe reemplazarla por una secuencia de '*' del mismo tamaño que s.

👉 En otras palabras: es como hacer un find & replace global, sustituyendo la palabra buscada por asteriscos.

GESTION ERRORES: 
- Si ocurre un error en read o malloc, debes imprimir: Error: <mensaje de error> poniendo el mensaje de error de stderr y devolver 1.
- Si el programa se llama sin argumentos, con argumento vacío, o con más de un argumento → debe devolver 1



FLUJO DEL PROGRAMA:
1) Validar argumentos:
    - Si no hay exactamente 1 argumento válido → return 1.

2) Leer desde stdin en bucles:
    - Usar read con un buffer.
    - Cada vez que leas, buscar ocurrencias de la cadena s dentro del bloque -> memmem.

3) Reemplazar ocurrencias:
    - Sustituir cada ocurrencia por '*' repetido tantas veces como la longitud de s ->memmove.

4) Escribir en stdout:
- Imprimir el bloque modificado con write.

Errores:
- Si read devuelve -1 → imprimir "Error: <mensaje>" con perror y salir con 1.
- Si malloc falla → lo mismo.
*/