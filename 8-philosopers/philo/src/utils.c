/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:15:49 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 12:39:34 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int exit_error(char *str)
{
    ft_putstr_fd(str, 2);
    return(1);
}

/* The gettimeofday function takes a parameter of type timeval, which is a structure with the following members:
	struct timeval {
    time_t      tv_sec;     // Number of seconds since January 1, 1970
    suseconds_t tv_usec;    // Number of microseconds (fractional part of seconds)

	In the subject it is asked to use milliseconds, so we need to convert everything from seconds to miliseconds (ms) before returning a value
*/

long get_time_ms()
{
    struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
void ft_usleep (long ms, t_data *data)
{
	long start; 

	start = get_time_ms();
	while((get_time_ms() - start) < ms)
	{
		if(is_simulation_over(data))
			break;
		usleep(500);
	}
}

//Comprueba si la simulacion ha terminado. 
// se crea un candado para evitar data races. Evitar que el hilo monitor y el hilo filosofo lean a medias. 
//Devuelve 0 si esta coriendo o 1 si ha finalizado. 
int is_simulation_over(t_data *data)
{
	int result; 
	
	pthread_mutex_lock(&data->death_mutex);
	result = data->simulation_over; 
	pthread_mutex_unlock(&data->death_mutex);
	return(result);
}


void print_state(t_philo *philo, char *state)
{
	long timestamp;
	
	pthread_mutex_lock(&philo->data->print_mutex);
	if(!is_simulation_over(philo->data))
	{
		timestamp = get_time_ms() - philo->data->start_time;
		printf("%ld %d %s\n", timestamp, philo->philo_id, state);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);	
}
int is_ready(t_data *data)
{
    int result;
    pthread_mutex_lock(&data->ready_mutex);
    result = data->ready;
    pthread_mutex_unlock(&data->ready_mutex);
    return (result);
}