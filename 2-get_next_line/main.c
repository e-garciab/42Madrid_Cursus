/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/04/01 12:12:16 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("./txt/test7.txt", O_RDONLY);
	// close (fd);
	// fd = -1;
	// fd = 100;
		str = "";
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("Resultado gnl: %s", str);
		printf("-----------------------\n");
		free(str);
	}
	close (fd);
	return (0);
}
