#include "get_next_line.h"

//Devuelve la longitud de un string

int ft_strlen(char *s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return(i);
}
int ft_strchr(char *s, char c)
{
    int i = 0;

    while(s && s[i])
    {
        if(s[i] == c)
            return(1);
        i++;
    }
    return(0);
} 

// Une dos strings en uno nuevo y libera el primero
char *ft_strjoin (char *s1, char *s2, int len2)
{
    char    *str; 
    int     len1;
    int     i = 0;
    int     j = 0;

    len1 = ft_strlen(s1);
    str = malloc((len1 + len2 + 1) * sizeof(char));
    if(!str)
    {
        free(s1);
        return(NULL);
    }
        while (s1 && s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    while(j < len2)
    {
        str[i] = s2[j];
        j++;
        i++;
    }
    str[i] = '\0';
    free(s1);
    return(str);
}

char *extract_line(char *saved)
{
    char *line; 
    int i = 0;

    if(!saved || !saved [0])
        return(NULL);
    while (saved[i] && saved[i] != '\n')
        i++;
    if(saved[i] == '\n')
        i++;
    line =malloc (i + 1);
    if(!line)
        return(NULL);
    i=0;
    while (saved[i] && saved[i] != '\n')
    {
        line[i] = saved [i];
        i++;
    }
    if(saved[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return(line);
}

char *update_saved (char *saved)
{
    char *new_saved;
    int i = 0;
    int j = 0;

    if(!saved)
        return(NULL);
    while (saved[i] && saved[i] != '\n')
        i++;
    if(!saved[i] || !saved[i +1])
    {
        free(saved);
        return(NULL);
    }
    i++;
    new_saved = malloc(ft_strlen (saved + i) +1);
    if(!new_saved)
    {
        free(saved);
        return(NULL);
    }
    while (saved[i])
    {
        new_saved[j] = saved[i];
        j++;
        i++;
    }
    new_saved[j] = '\0';
    free(saved);
    return(new_saved);
}


char *get_next_line(int fd)
{
    static char *saved; //variable estática que guarda lo que sobró de la llamada anterior
    char        *buffer;
    int         bytes_read;
    char        *line;

    if(fd<0 || BUFFER_SIZE <= 0)
        return(NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    bytes_read = 1;
    while(bytes_read > 0)
    {
        bytes_read = read(fd, buffer,BUFFER_SIZE);
        if(bytes_read < 0)
        {
            free(saved);
            saved = NULL; 
            return(NULL);
        } 
        saved = ft_strjoin(saved, buffer, bytes_read);
        if(!saved)
            return(NULL);
        if(ft_strchr(saved, '\n'))
            break;
    }
    free(buffer);
    line = extract_line(saved);
    saved = update_saved (saved);
    return(line);
}