/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:04 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/24 19:01:35 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Malloc failed");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iteration_definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}
static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	printf("mlx_ptr: %p\n", fractal->mlx_ptr);
	if (fractal->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error setting connection", 2);
		malloc_error();
	}
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->name);
	printf("win_ptr: %p\n", fractal->win_ptr);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	printf("img_ptr: %p\n", fractal->img_ptr);
	if (fractal->img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->addr = mlx_get_data_addr(fractal->img_ptr, &fractal->bpp,
			&fractal->line_len, &fractal->endian); //¿¿¿POR QUÉ BPP,
																												// LINE_LEN Y ENDIAN VAN POR REFERENCIA &????
	printf("addr: %p\n", fractal->addr);
	if (fractal->addr == NULL)
	{
		ft_putstr_fd("Error getting image data address\n", 2);
		malloc_error();
	}
	events_init(fractal);
	data_init(fractal);
}
