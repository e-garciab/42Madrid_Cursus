/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:26 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/09 19:04:09 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Display its PID
// Create an endless loop so that the server can receive signals at any time
// Receive signals
// Decrypt signals
    // For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action
//Tendría que salir cuando ya haya terminado de recibir la señal?? siempre se queda en espera.


void signal_handler(int sig)
{
    if(sig==SIGUSR1)
        write(1, "Bit 0\n", 7);
    if(sig==SIGUSR2)
        write(1, "Bit 1\n", 7);
}
/*    
int main(void)
{
    printf("El PID del servidor es: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while(1)
        pause();
    return(0);
}
*/



int main(void)
{
    struct sigaction sa; //Creamos una instancia de la estructura que configurará la señal.
    sa.sa_handler= signal_handler; // qué función se debe ejecutar cuando llegue la señal
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask); //sa_mask define qué señales se bloquean mientras se ejecuta el handler
        // sigemptyset indica que ninguna señal adicional será bloqueada durante la ejecución del handler.
    sigaction(SIGUSR1, &sa, NULL);
    
    printf("El PID del servidor es: %d\n", getpid());
    while(1)
        pause();
    return(0);
}