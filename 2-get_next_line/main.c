/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/03/05 19:41:37 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char *str;

	fd = open("./txt/test.txt", O_RDONLY);
	// fd = 0;
	str = get_next_line(fd);
	while (str)
	{	
		printf("Resultado gnl: %s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	// printf("Resultado gnl llamada 1: %s\n", str);
	// str = get_next_line(fd);
	// printf("Resultado gnl llamada 2: %s\n", str);
	// str = get_next_line(fd);
	// printf("Resultado gnl llamada 3: %s\n", str);
	// str = get_next_line(fd);
	// printf("Resultado gnl llamada 4: %s\n", str);
	close(fd);
	return(0);
}