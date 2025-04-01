/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:03:17 by marvin            #+#    #+#             */
/*   Updated: 2025/04/01 14:50:55 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

static char	*ft_read_line(int fd, char *buffer, char *stored)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stored);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!stored)
			stored = ft_strdup("");
		temp = stored;
		stored = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(stored, '\n'))
			break ;
	}
	return (stored);
}

static char	*ft_return_line(char **stored)
{
	int		len;
	char	*temp;
	char	*line;

	len = 0;
	while ((*stored)[len] != '\0' && (*stored)[len] != '\n')
		len++;
	line = ft_substr(*stored, 0, (len + 1));
	temp = *stored;
	*stored = ft_substr(*stored, (len + 1), (ft_strlen(*stored) - len));
	free(temp);
	temp = NULL;
	if (!(*stored) || (*stored)[0] == '\0')
	{
		free(*stored);
		*stored = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stored;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE < 0))
		return (NULL);
	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stored = ft_read_line(fd, buffer, stored);
	free(buffer);
	buffer = NULL;
	if (!stored)
		return (NULL);
	line = ft_return_line(&stored);
	return (line);
}
