/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:25:57 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/28 19:48:21 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_pixel_put(int x, int y, t_fractal *fractal, int color)
{
	int	offset;

	offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
	*(unsigned int *)(fractal->addr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (fractal->name && !ft_strncmp(fractal->name, "julia", 6))
	{
		c->real = fractal->julia_x;
		c->i = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}
void	init_complex_point(int x, int y, t_fractal *fractal, t_complex *z)
{
	t_range		old_range;
	t_range		new_range;
	
	old_range.min = 0;
	old_range.max = WIDTH;
	new_range.min = -2.0;
	new_range.max = +2.0;
	z->real = (map_value(x, old_range, new_range) * fractal->zoom)
		+ fractal->shift_x;
	old_range.min = 0;
	old_range.max = HEIGHT;
	new_range.min = +2.0;
	new_range.max = -2.0;
	z->i = (map_value(y, old_range, new_range) * fractal->zoom)
		+ fractal->shift_y;
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	init_complex_point(x, y, fractal, &z);
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->max_iter)
		{
			z = sum_complex(square_complex(z), c);
			if ((z.real * z.real) + (z.i * z.i) > fractal->escape_value)
			{
				// color = get_color(i);
				color = get_color(i, fractal);
				ft_pixel_put(x, y, fractal, color);
				return ;
			}
			i++;
		}
	ft_pixel_put(x, y, fractal, COLOR_BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img_ptr, 0, 0);
}
