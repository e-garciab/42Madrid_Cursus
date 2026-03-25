#include "get_next_line.h"

int main (void)
{
    int fd = open("./test.txt", O_RDONLY);
    //int fd = open("./test1.txt", O_RDONLY);
    //int fd = open("./test2.txt", O_RDONLY);
    //int fd = -8;
    char *str; 
    int line_counter = 1;

    while ((str = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s\n", line_counter, str);
        free(str);
        line_counter++;
    }
    printf("Line %d: %s\n", line_counter, str);
    close (fd);
    return(0);
}