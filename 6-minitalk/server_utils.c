/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:54:26 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/19 12:45:21 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void reset_client(t_state *s, pid_t new_pid)
{
	s->client_pid = new_pid;
	s->bit_count = 0;
	s->c = 0;
	s->index = 0;
	s->len_bits = 0;
	s->message_len = 0;
	s->expecting_len = 1;
	if (s->buffer)
	{
		free(s->buffer);
		s->buffer = NULL;
	}
}

static void	allocate_memory(t_state *s)
{
	s->expecting_len = 0;
	s->buffer = malloc(s->message_len + 1);
	if(!s->buffer)
	{
		ft_putstr_fd("Malloc failed", 2);
		exit(EXIT_FAILURE);
	}
	s->buffer[s->message_len] = '\0';
}

static void	finalize_message(t_state *s)
{
	ft_putstr_fd(s->buffer, 1);
	ft_putstr_fd("\n", 1);
	free(s->buffer);
	s->buffer = NULL;
	s->index = 0;
	s->expecting_len = 1;
	s->len_bits = 0;
	s->message_len = 0;
}

static void process_char(t_state *s)
{
	if(s->expecting_len)
	{
		s->message_len = ((s->message_len << 8) | s->c );
		s->len_bits += 8;
		if(s->len_bits == 32)
			allocate_memory(s);
	}
	else
	{
		s->buffer[s->index++] = s->c;
		if(s->index == s->message_len)
			finalize_message(s);
	}
	s->c = 0; 
	s->bit_count = 0;
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static t_state	s;
	
	(void)context;
	if (s.client_pid != info->si_pid)
		reset_client(&s, info->si_pid);
	s.c = s.c << 1;
	if (sig == SIGUSR1)
		s.c = s.c | 1;
	s.bit_count++;
	if (s.bit_count == 8)
		process_char(&s);
	if (kill(s.client_pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("Error sending signal acknowledgment\n", 2);
		exit(EXIT_FAILURE);
	}
}
