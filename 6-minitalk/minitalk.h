/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:53:31 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/19 12:45:32 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_state
{
	pid_t			client_pid;
	int				bit_count;
	unsigned char	c;
	int				index;
	int				expecting_len;
	int				len_bits;
	int				message_len;
	char			*buffer;
}	t_state;

void	signal_handler(int sig, siginfo_t *info, void *context);

#endif /*MINITALK_H*/