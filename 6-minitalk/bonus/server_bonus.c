/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:26 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/16 20:19:48 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	set_client_pid(pid_t sender_pid, pid_t *client_pid, int *bit_count, unsigned char *c, int *index, char **buffer)
{
	if(*client_pid != sender_pid) //si el pid del cliente cambia,se resetea el caracter y el contador para evitar errores y mezclas.
	{
		*client_pid=sender_pid;
		*bit_count = 0;
		*c = 0;
		*index = 0;
		if(*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
}

static void	allocate_char(int *index, char **buffer, unsigned char c)
{
	char *new_buff;
	
	new_buff = malloc((*index + 1 + 1) * sizeof(char));
	if(!new_buff)
	{
		ft_putstr_fd("Memory allocation failed", 1);
		exit(EXIT_FAILURE);
	}
	if(*buffer)
	{
		ft_memcpy(new_buff, *buffer, *index);
		free(*buffer);
	}
	new_buff[*index] = c;
	new_buff[*index + 1] = '\0';
	*buffer=new_buff;
	(*index)++;
}

static void finalize_message(char **buffer, int *index, pid_t client_pid)
{
	ft_putstr_fd(*buffer, 1);
	ft_putstr_fd("\n", 1);
	free(*buffer);
	*buffer = NULL;
	*index=0;
    if(kill(client_pid, SIGUSR2) == -1)
	{
		ft_putstr_fd("Error sending message acknowledgment\n", 2);
		exit(EXIT_FAILURE);
	} 
}


static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int  bit_count; //cuenta cuántos bits han llegado
	static pid_t    client_pid; //guarda el pid del cliente actual
	static unsigned char    c; //almacena el caracter en construcción
	static char *buffer; //espacio donde iremos guardando cada caracter
	static int index;  //indicará la posición actual en el buffer (donde meter el siguiente caracter)
	
	(void)context;
	set_client_pid(info->si_pid, &client_pid, &bit_count, &c, &index, &buffer);
	c = c << 1; //desplaza los bits de c una posición a la izquierda,lo que abre un hueco al final para añadir un nuevo bit
	if(sig == SIGUSR1)
		c = c | 1; //asegura que el último bit es 1. Si la señal recibida fue SIGUSR2 no hace falta hacer nada porque al hacer el shift ya pusiste un cero al final.
	bit_count++;
	if(bit_count == 8)
	{	
		allocate_char(&index, &buffer, c);
		if(c == '\0') //significa que ya se ha recibido la cadena completa,hay que imprimirla
            finalize_message(&buffer, &index, client_pid);
        c=0;
		bit_count=0;
	}
	if(kill(client_pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("Error sending signal acknowledgment\n", 2);
		exit(EXIT_FAILURE);
	} 
}
		
int	main(void)
{
	struct sigaction sa;                    
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;       
	sa.sa_flags = SA_SIGINFO;
	// sa.sa_mask =
	sigemptyset(&sa.sa_mask);
		// sa_mask define qué señales se bloquean mientras se ejecuta el handler
								// sigemptyset indica que ninguna señal adicional será bloqueada durante la ejecución del handler.
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
	
/*
EJEMPLO DEBUG:

01000001
01234567

bit		count = 0; c = 0 -> 00000000
bit		count = 1 -> 00000001
bit		count = 2; c=00000001 ->00000010
bit		count = 3; c = 00000010 -> 00000100
bit		count = 4; c = 00000100 -> 00001000
bit		count = 5; c = 00001000 -> 00010000
bit		count = 6; c = 00010000 -> 00100000
bit		count = 7; c = 00100000 -> 01000001
bit		count = 8
*/