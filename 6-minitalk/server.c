/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:26 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/15 17:47:20 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Display its PID
// Create an endless loop so that the server can receive signals at any time
// Receive signals
// Decrypt signals
    // For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action
//Tendría que salir cuando ya haya terminado de recibir la señal?? siempre se queda en espera.


// void signal_handler(int sig)
// {
//     if(sig==SIGUSR1)
//         write(1, "Bit 0\n", 7);
//     if(sig==SIGUSR2)
//         write(1, "Bit 1\n", 7);
// }

/*GUARDANDO TODO EL STRING EN UN BUFFER E IMPRIMIENDOLO AL FINAL*/
/*
void signal_handler(int sig, siginfo_t *info, void *context)
{
    static int  bit_count; //cuenta cuántos bits han llegado
    static pid_t    client_pid; //guarda el pid del cliente actual
    static unsigned char    c; //almacena el caracter en construcción
    static char buffer[BUFFER_SIZE]; //espacio donde iremos guardando cada caracter
    static int index; //indicará la posición actual en el buffer (donde meter el siguiente caracter)
    
    (void)context;
    if(client_pid != info->si_pid) //si el pid del cliente cambia, se resetea el caracter y el contador para evitar errores y mezclas.
    {
        bit_count = 0;
        c = 0;
        index = 0;
        memset(buffer, 0, BUFFER_SIZE);
    }
    client_pid=info->si_pid; // actualiza el client_pid para mantener el mismo emisor 
    c = c << 1; //desplaza los bits de c una posición a la izquierda, lo que abre un hueco al final para añadir un nuevo bit
    if(sig == SIGUSR1)
        c = c | 1; //asegura que el último bit es 1. Si la señal recibida fue SIGUSR2 no hace falta hacer nada porque al hacer el shift ya pusiste un cero al final.
    bit_count++;
    if(bit_count == 8)
    {
        if(c == '\0') //significa que ya se ha recibido la cadena completa, hay que imprimirla
        {
            buffer[index] = '\0';
            ft_putstr_fd(buffer, 1);
            ft_putstr_fd("\n", 1);
            index=0;
        }
        else
        {
            if(index < BUFFER_SIZE - 1)
            {
                buffer[index] = c;
                index++;
            }
            else
            {
                ft_putstr_fd("Error: no space in buffer, message is too long\n", 2);
                exit(EXIT_FAILURE);
            }
        }
        bit_count=0;
        c=0;
    }
    if(kill(client_pid, SIGUSR2) == -1)
    {
        ft_putstr_fd("Error sending confirmation\n", 2);
        exit(EXIT_FAILURE);
    }
}
    
*/
/*DEBUG:

01000001
01234567

bit count = 0; c = 0 -> 00000000
bit count = 1 -> 00000001
bit count = 2; c=00000001 ->00000010
bit count = 3; c = 00000010 -> 00000100
bit count = 4; c = 00000100 -> 00001000
bit count = 5; c = 00001000 -> 00010000
bit count = 6; c = 00010000 -> 00100000
bit count = 7; c = 00100000 -> 01000001
bit count = 8
*/


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
/*
//ver diferencia con este código:
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit_count));
*/

/*ENVIANDO A IMPRIMIR CARACTER A CARACTER*/

void signal_handler(int sig, siginfo_t *info, void *context)
{
    static int  bit_count; //cuenta cuántos bits han llegado
    static pid_t    client_pid; //guarda el pid del cliente actual
    static unsigned char    c; //almacena el caracter en construcción
    
    (void)context;
    if(client_pid != info->si_pid) //si el pid del cliente cambia, se resetea el caracter y el contador para evitar errores y mezclas.
    {
        bit_count = 0;
        c = 0;
    }
    client_pid=info->si_pid; // actualiza el client_pid para mantener el mismo emisor 
    c = c << 1; //desplaza los bits de c una posición a la izquierda, lo que abre un hueco al final para añadir un nuevo bit
    if(sig == SIGUSR1)
        c = c | 1; //asegura que el último bit es 1. Si la señal recibida fue SIGUSR2 no hace falta hacer nada porque al hacer el shift ya pusiste un cero al final.
    bit_count++;
    if(bit_count == 8)
    {
        if(c == '\0')
        {
            write(1, "\n", 1);
            kill(client_pid, SIGUSR1); //REVISAR PARA BONUS - ENVIAR CONFIRMACIOIN DE FIN DEL MENSAJE.
        }        
        else 
            write(1, &c, 1);
        bit_count=0;
        c=0;
    }
    if(kill(client_pid, SIGUSR2) == -1)
    {
        ft_putstr_fd("Error sending confirmation\n", 2);
        exit(EXIT_FAILURE);
    }
}


int main(void)
{
    struct sigaction sa; //Creamos una instancia de la estructura que configurará la señal / creo la "caja"
    ft_printf("Server PID: %d\n", getpid()); // CUIDADO - CAMBIAR A MI FUNCION PRINTF
    sa.sa_sigaction= signal_handler; // qué función se debe ejecutar cuando llegue la señal
    sa.sa_flags = SA_SIGINFO;
    //sa.sa_mask = 
    sigemptyset(&sa.sa_mask); //sa_mask define qué señales se bloquean mientras se ejecuta el handler
        // sigemptyset indica que ninguna señal adicional será bloqueada durante la ejecución del handler.
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(1)
        pause();
    return(0);
}