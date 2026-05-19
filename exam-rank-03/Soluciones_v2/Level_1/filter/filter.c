#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

// abcHolaabcMundo
// result = 0
// pos = 3
// len = 15
// target = abc 
// target_ln = 3
// found = 7
// 15 - 

void ft_filter (char *result, size_t len, char *target)
{
    size_t target_len;
    char *pos;
    char *found;
    size_t i;

    target_len = strlen(target);
    pos = result;
    while((found = memmem(pos, len - (pos - result), target, target_len)) != NULL) // revisar!! (e lugar de len es len - (pos - buf))
    {
        write(1, pos, found-pos);
        i=0;
        while (i < target_len)
        {
            write(1, "*", 1);
            i++;
        }
        pos = found + target_len;
    }
    write (1, pos, len - (pos - result));
}

int main (int argc, char *argv[])
{
    int bytes;
    size_t total;
    char buffer[BUFFER_SIZE];
    char *tmp;
    char *result;

    if (argc != 2 || argv[1][0] == '\0') //valida args, si el usuario no pasa exactamente 1 argumento o el arg es una cadena vacía, sale con error y devuelve 1
        return(1);
    total = 0;
    result = NULL;
    while ((bytes = read(0, buffer, BUFFER_SIZE)) > 0)
    {
        tmp = realloc (result, total + bytes);
        if(!tmp)
        {
            free(result);
            perror("Error");
            return(1);
        }
        result = tmp;
        memmove(result + total, buffer, bytes); // copia temp al final de result
        total += bytes;
    }
    if (bytes < 0) // error de lectura
    {
        free(result);
        perror("Error");
        return(1);
    }
    if (!result) // no se leyó nada (stdin vacío)
        return(0);
    ft_filter(result,total, argv[1]);
    free(result);
    return(0);
}

/*
Imagina que stdin tiene: "abcHOLA"
Con BUFFER_SIZE 3, read te da los datos a trozos:
1ª llamada: temp = "abc"   total = 3
2ª llamada: temp = "HOL"   total = 6
3ª llamada: temp = "A"     total = 7

void *memmem(const void haystack[.haystacklen], size_t haystacklen,
                    const void needle[.needlelen], size_t needlelen);

DESCRIPTION
       The memmem() function finds the start of the first occurrence of the substring needle of length needle‐
       len in the memory area haystack of length haystacklen.
       The  memmem() function returns a pointer to the beginning of the substring, or NULL if the substring is
       not found.
*/