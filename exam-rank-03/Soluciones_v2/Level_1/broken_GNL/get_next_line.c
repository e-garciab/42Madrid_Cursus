#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i; 
    char *str; 
    int rd;
    char c;

    i=0;
    str=malloc(10000);
    if(!str)
        return NULL;
    if(BUFFER_SIZE <= 0)
    {
        free(str);
        return NULL;
    }
    while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE +1)) > 0)
    {
        str[i] = c; 
        if(str[i] == '\n')
            break;
        if(i >= 9999)
            break;
        i++;
    }
    if(rd < 0)
    {
        free(str);
        return NULL;
    }
    if(i == 0)
    {
        free(str);
        return NULL;
    }
    str[i] = '\0';
    return(str);   
}