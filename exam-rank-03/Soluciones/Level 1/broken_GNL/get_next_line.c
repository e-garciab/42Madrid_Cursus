#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *str;
    int i;
    int rd;
    char c;

    i=0;
    str = malloc(10000);
    if(!str)
        return (NULL);
    if(BUFFER_SIZE <= 0)
    {
        free(str);
        return(NULL);
    }
    while((rd = read(fd,&c,BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        str[i] = c;
        if(c == '\n')
            break;
        if(i >= 9999) //para evitar overflow
            break;
        i++;
    }
    if(rd == -1) //error de lectura
    {
        free(str);
        return(NULL);
    }
    if (i == 0) //EOF inmediato, no s leyó nada
    {
        free(str);
        return(NULL);
    }
    str[i] = '\0';
    return (str);
}