/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/04/01 15:02:00 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	char	*str;

	fd1 = open("./txt/test.txt", O_RDONLY);
	fd2 = open("./txt/test2.txt", O_RDONLY);
	fd3 = open("./txt/test4.txt", O_RDONLY);
	fd4 = open("./txt/test6.txt", O_RDONLY);
	fd5 = -1;
	str = "";
	while (str != NULL)
	{
		str = get_next_line(fd1);
		str = get_next_line(fd2);
		str = get_next_line(fd3);
		str = get_next_line(fd4);
		str = get_next_line(fd5);
		printf("Resultado gnl: %s", str);
		printf("-----------------------\n");
		free(str);
	}
	close (fd1);
	close (fd2);
	close (fd3);
	close (fd4);
	close (fd5);
	return (0);
}
