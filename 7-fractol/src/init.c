/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:04 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/28 20:15:11 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_init_window(t_fractal *fractal)
{
	fractal->mlx_ptr = NULL; 
	fractal->win_ptr = NULL;
	
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		exit_with_error("MLX init failed");
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->name);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		exit_with_error("Window creation failed");
	}
}

static void	fractal_init_image(t_fractal *fractal)
{
	fractal->img_ptr = NULL; 
	fractal->addr = NULL;
		
	fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		exit_with_error("Image creation failed");
	}
	fractal->addr = mlx_get_data_addr(fractal->img_ptr, &fractal->bpp,
			&fractal->line_len, &fractal->endian); 
	if (fractal->addr == NULL)
	{
		mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		exit_with_error("Image data address failed");
	}
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->max_iter = 80;
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
	fractal_init_window(fractal);
	fractal_init_image(fractal);
	data_init(fractal);
	events_init(fractal);
}