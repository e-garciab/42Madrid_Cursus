/*
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

// int main(void)
// {
//     struct timeval  tv;

//     gettimeofday(&tv, NULL);
//     printf("tv_sec  (segundos):      %ld\n", tv.tv_sec);
//     printf("tv_usec  (microsegundos):      %ld\n", tv.tv_usec);
//     printf("milisegundos):      %ld\n", ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
//     return(0);
// }

long    get_time_ms(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main(void)
{
    long    start;
    long    end;

    start = get_time_ms();
    usleep(200 * 1000);        // pedimos 200ms
    end = get_time_ms();
    printf("Pedimos: 200ms | Real: %ldms\n", end - start);
    return (0);
}

*/