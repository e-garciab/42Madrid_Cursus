/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:26 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/17 17:34:24 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	set_client_pid(pid_t sender_pid, pid_t *client_pid, int *bit_count,
		unsigned char *c, int *index, char **buffer)
{
	if (*client_pid != sender_pid)
	{
		*client_pid = sender_pid;
		*bit_count = 0;
		*c = 0;
		*index = 0;
		if (*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
}

static void	allocate_char(int *index, char **buffer, unsigned char c)
{
	char	*new_buff;

	new_buff = malloc((*index + 1 + 1) * sizeof(char));
	if (!new_buff)
	{
		ft_putstr_fd("Memory allocation failed", 1);
		exit(EXIT_FAILURE);
	}
	if (*buffer)
	{
		ft_memcpy(new_buff, *buffer, *index);
		free(*buffer);
	}
	new_buff[*index] = c;
	new_buff[*index + 1] = '\0';
	*buffer = new_buff;
	(*index)++;
}

static void	finalize_message(char **buffer, int *index, pid_t client_pid)
{
	ft_putstr_fd(*buffer, 1);
	ft_putstr_fd("\n", 1);
	free(*buffer);
	*buffer = NULL;
	*index = 0;
	if (kill(client_pid, SIGUSR2) == -1)
	{
		ft_putstr_fd("Error sending message acknowledgment\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				bit_count;
	static pid_t			client_pid;
	static unsigned char	c;
	static char				*buffer;
	static int				index;

	(void)context;
	set_client_pid(info->si_pid, &client_pid, &bit_count, &c, &index, &buffer);
	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	bit_count++;
	if (bit_count == 8)
	{
		allocate_char(&index, &buffer, c);
		if (c == '\0')
			finalize_message(&buffer, &index, client_pid);
		c = 0;
		bit_count = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("Error sending signal acknowledgment\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
