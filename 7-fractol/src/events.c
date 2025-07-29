/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:36:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/28 19:19:14 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		close_handler(fractal);
	else if (keycode == KEY_LEFT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keycode == KEY_RIGHT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keycode == KEY_UP)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keycode == KEY_DOWN)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keycode == KEY_PLUS)
		fractal->max_iter += 10;
	else if (keycode == KEY_MINUS)
		fractal->max_iter -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void) x;
	(void) y;
	if (button == SCROLL_UP)
		fractal->zoom *= 1.05;
	else if (button == SCROLL_DOWN)
		fractal->zoom *= 0.95;
	fractal_render(fractal);
	return (0);
}
