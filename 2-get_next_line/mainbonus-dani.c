// #include "get_next_line_bonus.h"

// int main(int ac, char **av)
// {
// 	if (ac < 2)
// 	{
// 		printf("Invalid number of arguments.\n");
// 		return (0);
// 	}
// 	if (ac > 7)
// 	{
// 		printf("Too many arguments.\n");
// 		return (0);
// 	}
// 	if (BUFFER_SIZE <= 0)
// 	{
// 		printf("Invalid buffer size.\n");
// 		return (0);
// 	}
// 	int fd1 = 0;
// 	int fd2 = 0;
// 	int fd3 = 0;
// 	int fd4 = 0;
// 	int fd5 = 0;
// 	int fd6 = 0;
// 	if (ac >= 2)
// 	{
// 		fd1 = open(av[1], O_RDONLY);
// 		if (fd1 < 0)
// 			fd1 = 0;
// 	}
// 	if (ac >= 3)
// 	{
// 		fd2 = open(av[2], O_RDONLY);
// 		if (fd2 < 0)
// 			fd2 = 0;
// 	}
// 	if (ac >= 4)
// 	{
// 		fd3 = open(av[3], O_RDONLY);
// 		if (fd3 < 0)
// 			fd3 = 0;
// 	}
// 	if (ac >= 5)
// 	{
// 		fd4 = open(av[4], O_RDONLY);
// 		if (fd4 < 0)
// 			fd4 = 0;
// 	}
// 	if (ac >= 6)
// 	{
// 		fd5 = open(av[5], O_RDONLY);
// 		if (fd5 < 0)
// 			fd5 = 0;
// 	}
// 	if (ac >= 7)
// 	{
// 		fd6 = open(av[6], O_RDONLY);
// 		if (fd6 < 0)
// 			fd6 = 0;
// 	}
		
// 	char *line;
// 	while (fd1 != 0 || fd2 != 0 || fd3 != 0 || fd4 != 0 || fd5 != 0 || fd6 != 0)
// 	{
// 		line = get_next_line(fd1);
// 		if (fd1 != 0 && line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 		}
// 		else if (fd1 != 0)
// 		{
// 			close(fd1);
// 			fd1 = 0;
// 		}
// 		line = get_next_line(fd2);
// 		if (fd2 != 0 && line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 		}
// 		else if (fd2 != 0)
// 		{
// 			close(fd2);
// 			fd2 = 0;
// 		}
// 		line = get_next_line(fd3);
// 		if (fd3 != 0 && line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 		}
// 		else if (fd3 != 0)
// 		{
// 			close(fd3);
// 			fd3 = 0;
// 		}
// 		line = get_next_line(fd4);
// 		if (fd4 != 0 && line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 		}
// 		else if (fd4 != 0)
// 		{
// 			close(fd4);
// 			fd4 = 0;
// 		}
// 		line = get_next_line(fd5);
// 		if (fd5 != 0 && line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 		}
// 		else if (fd5 != 0)
// 		{
// 			close(fd5);
// 			fd5 = 0;
// 		}
// 		line = get_next_line(fd6);
// 		if (fd6 != 0 && line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 		}
// 		else if (fd6 != 0)
// 		{
// 			close(fd6);
// 			fd6 = 0;
// 		}
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	close(fd4);
// 	close(fd5);
// 	close(fd6);
// 	return (0);
// }