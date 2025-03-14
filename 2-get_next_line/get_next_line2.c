/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:03:17 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 12:03:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *read_fd(int fd, char *buffer, char *stored)
{
    size_t	bytes_read;
	char	*temp;
    
    bytes_read = 1;
	while(bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{	
			free(buffer);
			return(NULL);
		}
		else if (bytes_read == 0)
            break ;
		buffer[bytes_read] = '\0';
		if(!stored)
			stored = ft_strdup(buffer);
		temp = stored;
		stored = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(stored, '\n'))
			break ;
	}
    return(stored);
}


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
	stored = read_fd(fd, buffer, stored);
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