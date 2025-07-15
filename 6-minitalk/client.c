/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/15 17:44:50 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Write a program (main) in which the client takes two parameters/arguments:
    // 1)The PID of the server to which it wants to send the message
    // 2) A message
// Encrypt the message (I did the encryption via bits)
// Send the message to the server (via its PID)
// Create a stop condition so that the server knows when it has finished receiving the message


// void send_char(pid_t pid, char c)
// {
//     int i; 
//     i=7;

//     while (i>=0)
//     {
//         if((c >> i) & 1)
//             kill(pid, SIGUSR1);
//         else 
//             kill(pid, SIGUSR2);
//         usleep(100);
//         i--;
//     }
// }
int g_confirm_flag = 0; //VARIABLE GLOBAL

void confirm_handler(int sig)
{
    if(sig == SIGUSR2)
        g_confirm_flag = 1;
    else if(sig == SIGUSR1)
    {
        ft_printf("Message received\n");
        exit(EXIT_SUCCESS);
    }
}

void send_bit(int pid, int bit)
{
    int signal; 

    if(bit == 1)
        signal = SIGUSR1;
    else
        signal = SIGUSR2;
    if(kill(pid, signal) == -1)
    {
        ft_putstr_fd("Error sending signal\n", 2);
        exit(EXIT_FAILURE);
    }
    while(g_confirm_flag == 0)
        pause();
    g_confirm_flag = 0;
}

void send_char(int pid, unsigned char c)
{
    int i;
    
    i=7;
    while(i >=0)
    {
        send_bit(pid, (c >> i) & 1);
        //usleep(100);
        i--;
    }
}


void send_string(int pid, const char *str)
{
    int i;
    
    i=0;
    while(str[i] != '\0')
    {
        send_char(pid, str[i]);
        i++;        
    }
    send_char(pid, '\0');
}

int main(int argc, char *argv[])
{
    pid_t pid;
    
    if(argc != 3)
    {
        ft_putstr_fd("Invalid number of arguments\n", 2);
        exit(EXIT_FAILURE);
    }
    pid = ft_atoi(argv[1]);
    if(pid <= 0)
    {
        ft_putstr_fd("Invalid PID\n", 2);
        exit(EXIT_FAILURE);
    }       
    signal(SIGUSR2, confirm_handler);
    send_string(pid, argv[2]);
    return(0);
}