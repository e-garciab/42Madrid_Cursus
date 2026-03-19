/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 10:02:51 by egarcia2          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/15 21:14:54 by egarcia2         ###   ########.fr       */
=======
/*   Updated: 2026/03/17 20:50:55 by egarcia2         ###   ########.fr       */
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

<<<<<<< HEAD
// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

int main (int argc, char *argv[])
{
    t_data data;
    pthread_t monitor;
        
    if(!check_args(argc, argv, &data))
        return(1);
    if(!init_data(&data))
    {
        cleanup (&data);
        return(1);
    }
    printf("filosofos: %d | Die: %ld | Eat: %ld | Sleep: %ld | Must eat: %d\n", data.nbr_philos, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.nbr_must_eat);
    if(!launch_philos(&data))
    {
        cleanup (&data);
        return(1);  
    }
    if(pthread_create(&monitor, NULL, monitor_routine, &data) != 0)
    {
       cleanup (&data);
       return(1);   
    }
    if(pthread_join(monitor, NULL) != 0)
    {
       cleanup (&data);
       return(1);  
    }
    if(!join_philos(&data))
    {
        cleanup (&data);
        return(1);  
    }
    cleanup (&data);
    return(0);   
}
    





=======
// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep 
// [number_of_times_each_philosopher_must_eat]

int	main(int argc, char *argv[])
{
	t_data		data;
	pthread_t	monitor;

	if (!check_args(argc, argv, &data))
		return (1);
	if (!init_data(&data))
	{
		cleanup(&data);
		return (1);
	}
	// printf("filosofos: %d | Die: %ld | Eat: %ld | Sleep: %ld | Must eat: %d\n",
	// 	data.nbr_philos, data.time_to_die, data.time_to_eat, data.time_to_sleep,
	// 	data.nbr_must_eat);
	if (!launch_philos(&data))
	{
		cleanup(&data);
		return (1);
	}
	if (pthread_create(&monitor, NULL, monitor_routine, &data) != 0)
	{
		cleanup(&data);
		return (1);
	}
	if (pthread_join(monitor, NULL) != 0)
	{
		cleanup(&data);
		return (1);
	}
	if (!join_philos(&data))
	{
		cleanup(&data);
		return (1);
	}
	cleanup(&data);
	return (0);
}
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d

// void *routine()
// {
//     printf("Test from threads\n");
//     sleep (3);
//     printf("Ending thread\n");
// }

<<<<<<< HEAD

=======
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
// int main(int argc, char *argv[])
//  {
//     pthread_t   t1;
//     pthread_t   t2;

//     if(pthread_create(&t1, NULL, &routine, NULL) != 0)
<<<<<<< HEAD
//         return 1;
//     if(pthread_create(&t2, NULL, &routine, NULL) != 0)
//          return 2;
//     if(pthread_join(t1, NULL) != 0)
//          return 3;
//     if(pthread_join(t2, NULL) != 0)
//         return 4;
=======
//         return (1);
//     if(pthread_create(&t2, NULL, &routine, NULL) != 0)
//          return (2);
//     if(pthread_join(t1, NULL) != 0)
//          return (3);
//     if(pthread_join(t2, NULL) != 0)
//         return (4);
>>>>>>> 11af22a0d168925e3a399f68c10c435fcaea5d9d
//     return(0);
//  }