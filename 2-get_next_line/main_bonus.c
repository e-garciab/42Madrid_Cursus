/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:02 by egarcia2          #+#    #+#             */
/*   Updated: 2025/04/02 14:38:56 by egarcia2         ###   ########.fr       */
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
	int		line_counter;	

	line_counter = 1;
	fd1 = open("./txt/test.txt", O_RDONLY);
	fd2 = open("./txt/test2.txt", O_RDONLY);
	fd3 = open("./txt/test3.txt", O_RDONLY);
	fd4 = open("./txt/test4.txt", O_RDONLY);
	fd5 = open("./txt/test7.txt", O_RDONLY);
	str = "";
	while (str != NULL)
	{
		str = get_next_line(fd1);
		printf("%d   %s", line_counter, str);
		str = get_next_line(fd2);
		printf("%d   %s", line_counter, str);
		str = get_next_line(fd3);
		printf("%d   %s", line_counter, str);
		str = get_next_line(fd4);
		printf("%d   %s", line_counter, str);
		str = get_next_line(fd5);
		printf("%d   %s", line_counter, str);
		printf("-----------------------\n");
		free(str);
		line_counter++;
	}
	close (fd1);
	close (fd2);
	close (fd3);
	close (fd4);
	close (fd5);
	return (0);
}
