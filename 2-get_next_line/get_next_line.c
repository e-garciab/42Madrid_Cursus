/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:00:21 by egarcia2          #+#    #+#             */
/*   Updated: 2025/03/05 19:42:00 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*buffer;
	static char *stored;
	size_t	bytes_read;
	char	*temp;
	int 	len;
	char	*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return(NULL);
	memset(buffer, 0, (BUFFER_SIZE + 1));
	
	bytes_read = 1;
	while(bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{	
			printf("Error reading the file");
			free(buffer);
			return(NULL);
		}
		else if (bytes_read == 0)
		{	
			buffer[0] = '\0';
			printf("Nothing to read\n");
            break ;
			// printf("contenido buffer %s\n", buffer);
			// free(buffer);
			// return(NULL);
		}
		else
		{	
			buffer[bytes_read] = '\0';
			printf("bytes_leidos: %d\n", bytes_read);
			printf("contenido buffer: %s\n", buffer);
		}
		if(!stored)
		{	
			stored = ft_strdup(buffer);
			printf("contenido stored: %s\n", stored);
			//printf("direccion de memoria de stored: %p\n", stored);
		}
		else
		{	
			//printf("direccion de memoria de stored antes de join: %p\n", stored);
			temp = stored;
			//printf("direccion de memoria de temp antes de join: %p\n", temp);
			stored = ft_strjoin(temp, buffer);
			free(temp);
			printf("contenido stored: %s\n", stored);
			//printf("direccion de memoria de stored despues de join: %p\n", stored);
		}
		if (ft_strchr(stored, '\n'))
			break ;
	}

	free(buffer);
    if (!stored || stored[0] == '\0')
        return (NULL);

	len = 0;
	while (stored[len] != '\0' && stored[len] != '\n')
		len++; 

	line = ft_substr(stored, 0, (len + 1));
    temp = stored;
    stored = ft_substr(stored, (len + 1), (ft_strlen(stored) - len));
	free(temp);
	
	printf("contenido stored: %s\n", stored);
	printf("contenido line: %s\n", line);
	return(line);
}