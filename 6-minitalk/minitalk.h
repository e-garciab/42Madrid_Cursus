/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:53:31 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/16 10:27:55 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif /*BUFFER_SIZE*/

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include <signal.h>    // para usar señales como SIGUSR1 y kill
# include <sys/types.h> //para el tipo de dato pid_t
# include <unistd.h>    // para write y pause
# include <stdio.h>
# include <stdlib.h>

#endif /*MINITALK_H*/