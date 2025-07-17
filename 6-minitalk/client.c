/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/17 20:06:18 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_confirm_flag = 0;

static void	confirm_handler(int sig)
{
	if (sig == SIGUSR1)
		g_confirm_flag = 1;
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

static void	send_char(int server_pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(server_pid, (c >> i) & 1);
		i--;
	}
}

static void	send_string(int server_pid, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;

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
	send_string(server_pid, argv[2]);
	return (0);
}
