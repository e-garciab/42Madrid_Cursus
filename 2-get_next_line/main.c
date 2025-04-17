/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/04/02 14:18:35 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*str;
	int		line_counter;	

	line_counter = 1;
	fd = open("./txt/test.txt", O_RDONLY);
	// close (fd);
	// fd = -1;
	// fd = 100;
	while ((str = get_next_line(fd)))
	{
		printf("%d   %s", line_counter, str);
		line_counter++;
		free(str);
	}
	printf("%s", str);
	close (fd);
	return (0);
} */
