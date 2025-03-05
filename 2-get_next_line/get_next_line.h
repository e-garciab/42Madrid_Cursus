/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:00:43 by egarcia2          #+#    #+#             */
/*   Updated: 2025/03/05 19:42:08 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdio.h>		//revisar
# include <unistd.h>	//revisar
# include <fcntl.h>		//revisar
# include <string.h>	//revisar
# include <stdlib.h>	//revisar

char *get_next_line(int fd);


#endif /*GET_NEXT_LINE_H*/