/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/19 12:56:02 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int			g_confirm_flag = 0;

static void	confirm_handler(int sig)
{
	if (sig == SIGUSR1)
		g_confirm_flag = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Message received by server\n");
		exit(EXIT_SUCCESS);
	}
}

static void	send_bit(int server_pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(server_pid, signal) == -1)
	{
		ft_putstr_fd("Error sending signal\n", 2);
		exit(EXIT_FAILURE);
	}
	while (g_confirm_flag == 0)
		pause();
	g_confirm_flag = 0;
}

static void send_int(int server_pid, int num)
{
	int i;
	
	i= 31;
	while (i >= 0)
	{
		send_bit(server_pid,(num >> i) & 1);
		i--;
	}
}

static void	send_string(int server_pid, const char *str)
{
	int	i;
	int bit;
	
	i = 0;
	while (1)
	{
		bit = 7;
		while (bit >= 0)
		{
			send_bit(server_pid, (str[i] >> bit) & 1);
			bit--;
		}
		if(str[i] == '\0')
			break;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	int 	len;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, confirm_handler);
	signal(SIGUSR2, confirm_handler);
	len = strlen(argv[2]) + 1;
	send_int(server_pid, len);
	send_string(server_pid, argv[2]);
	return (0);
}
