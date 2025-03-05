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
	char a;
	ssize_t result;
	char *str;
	int i;
	
	i = 0;
	str = malloc(BUFFER_SIZE * sizeof(char));
	if (str == NULL)
		return (NULL);
	result = read(fd, &a, 1);
	while (result > 0)
	{	
		if (a == '\n')
		{	
			str[i] = a;
			i++;
			break;
		}
		str[i] = a;
		i++;
		result = read(fd, &a, 1);
	}
	str[i] = '\0';
	if(result == 0)
	{
		free(str);
		return (NULL);		
	}
	return(str);
}

/*
static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	ssize_t	result;
	int		i;
	
	buffer = malloc(BUFFER_SIZE * sizeof(char));
		if (buffer == NULL)
		return (NULL);
	result = read(fd, buffer, BUFFER_SIZE);
	printf("buff_leido: %s\n", buffer);
	printf("bytes_leidos: %zd\n", result);
	if (result == -1)
		return (NULL);
	if (result == 0)
		return (NULL);
	if (result > 0)
	{
		if (!str)
		str = strdup(buffer);

		
		while(buffer[i] != '\0')
		{
			str = ft_strdup(buffer);
			
			printf("str_leido: %s\n", str);
			if
		}

	}
	return(0);

	
}




// 	// printf("buff_leido: %s\n", buffer);

// 	i = 0;
	
// 	{
// 		if(buffer[i] != '\n') 
	
// 		result = read(fd, &buffer[i], 1);
// 		if (result == -1)
// 			return (NULL);
// 		str[i] = strdup(&buffer[i]);
// 		free(buffer);
// 		i++;
// 	}
// 		printf("str_leido: %s\n", str);

// 	return (str);

	
// 	//printf("bytes_leidos: %zd\n", result);
// }
// */

