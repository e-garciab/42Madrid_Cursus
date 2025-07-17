/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:23 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/17 17:33:16 by egarcia2         ###   ########.fr       */
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

static void	send_bit(int pid, int bit)
{
	int	signal;

	if (bit == 1)
		signal = SIGUSR1;
	else
		signal = SIGUSR2;
	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd("Error sending signal\n", 2);
		exit(EXIT_FAILURE);
	}
	while (g_confirm_flag == 0)
		pause();
	g_confirm_flag = 0;
}

static void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(pid, (c >> i) & 1);
		i--;
	}
}

static void	send_string(int pid, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, confirm_handler);
	signal(SIGUSR2, confirm_handler);
	send_string(pid, argv[2]);
	return (0);
}
