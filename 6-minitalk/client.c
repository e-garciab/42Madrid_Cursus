/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/11 14:40:43 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Write a program (main) in which the client takes two parameters/arguments:
    // 1)The PID of the server to which it wants to send the message
    // 2) A message
// Encrypt the message (I did the encryption via bits)
// Send the message to the server (via its PID)
// Create a stop condition so that the server knows when it has finished receiving the message


void send_char(pid_t pid, char c)
{
    int i; 
    i=7;

    while (i>=0)
    {
        if((c >> i) & 1)
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        usleep(100);
        i--;
    }
}

int main(int argc, char *argv[])
{
    pid_t pid;
    
    if(argc != 2)
    {
        write(2, "Too few arguments", 17);
        return(1);
    }
    pid = ft_atoi(argv[1]);
    send_char(pid, 'A');
    
    // if(kill(pid, SIGUSR1) == -1)
    // {
    //     write(2, "Error sending signal", 20);
    //     return(1);
    //}
    return(0);
}