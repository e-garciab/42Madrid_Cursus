/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/03/25 14:03:03 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("./txt/test5.txt", O_RDONLY);
	//fd = -1;
	str = "";
	while (str != NULL)
	{
		str = get_next_line(fd);
		printf("Resultado gnl: %s\n", str);
		free(str);
	}
	close (fd);
	return (0);
}
