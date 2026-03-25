#include "get_next_line.h"

int main(void)
{
    int i;
    char *str; 
    int fd; 

    fd= open("./test.txt", O_RDONLY);
    while((str = get_next_line(fd)) != NULL)
    {
        printf("Linea leida: %s", str);
        free(str);
    }
    printf("Linea leida: %s\n", str);
    close (fd);
    return(1);
}