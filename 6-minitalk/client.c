/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/07 17:13:58 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Write a program (main) in which the client takes two parameters/arguments:
    // 1)The PID of the server to which it wants to send the message
    // 2) A message
// Encrypt the message (I did the encryption via bits)
// Send the message to the server (via its PID)
// Create a stop condition so that the server knows when it has finished receiving the message


int main(int argc, char *argv[])
{
    pid_t pid;
    
    if(argc != 2)
    {
        write(2, "Too few arguments", 17);
        return(1);
    }
    pid = atoi(argv[1]);
    if(kill(pid, SIGUSR1) == -1)
    {
        write(2, "Error sending signal", 20);
        return(1);
    }
    return(0);
}