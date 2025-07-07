/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:26 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/07 17:04:48 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Display its PID
// Create an endless loop so that the server can receive signals at any time
// Receive signals
// Decrypt signals
    // For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action


void signal_handler(int sig)
{
    if(sig==SIGUSR1)
        write(1, "Señal SIGUSR1 recibida\n", 24);
}
    
int main(void)
{
    printf("El PID del servidor es: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    while(1)
        pause();
    return(0);
}