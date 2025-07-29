/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:30:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/28 11:46:54 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_with_error(char *message)
{
	ft_putstr_fd(message, 2);
	perror("");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 6)))
	{
		fractal.name = argv[1];
		if(!ft_strncmp(fractal.name, "julia", 6))
        {
            fractal.julia_x = ft_atof(argv[2]);
		    fractal.julia_y = ft_atof(argv[3]);
        }
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Invalid arguments. Please enter:\n\t 1) \"./fractol mandelbrot\" or \n\t 2) \"./fractol julia <real value> <imaginary value>\"\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}


