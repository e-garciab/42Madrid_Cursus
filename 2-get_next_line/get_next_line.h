/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:00:43 by egarcia2          #+#    #+#             */
/*   Updated: 2025/03/26 13:39:45 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif /*BUFFER_SIZE*/

# include <stdio.h> //necesaria para printf (main)
# include <unistd.h> //necesaria para read y close
# include <stdlib.h> //necesaria para malloc y free
# include <fcntl.h> //necesaria para open

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif /*GET_NEXT_LINE_H*/