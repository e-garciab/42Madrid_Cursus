/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:48:37 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/24 19:02:00 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/fractol.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;

	int x; // eje horizontal
	int y; // eje vertical
	width = 800;
	height = 600;
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		ft_putstr_fd("Error setting connection", 2);
	win_ptr = mlx_new_window(mlx_ptr, width, height, "Hello MLX in WSL!");
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	mlx_pixel_put(mlx_ptr, win_ptr, width / 2, height / 2, 0x00FF00);
	addr = mlx_get_data_addr(img_ptr, &bpp, &line_len, &endian);
	ft_printf("Dirección: %p", addr);
	// mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

/* COPY HANDLE PIXEL:

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	t_range		old_range;
	t_range		new_range;
	int			i;
	int			color;

	i=0;
	old_range.min = 0;
	old_range.max = WIDTH;
	new_range.min = -2.0;
	new_range.max = +2.0;
	c.real = (map_value(x, old_range, new_range) * fractal->zoom)
		+ fractal->shift_x;
	old_range.min = 0;
	old_range.max = HEIGHT;
	new_range.min = +2.0;
	new_range.max = -2.0;
	c.i = (map_value(y, old_range, new_range) * fractal->zoom)
		+ fractal->shift_y;
	z.real = 0.0;
	z.i = 0.0;
	while(i < fractal->iteration_definition)
		//¿cuantas veces tiene que iterar z^2
		+ c para ver si el punto se escapa?
	{
		//z = z^2 + c
		z = sum_complex(square_complex(z), c);
		//is the value escaped?? if hypothenuse > 2 asumo que el valor se ha escapado
		if((z.real * z.real) + (z.i * z.i) > fractal->escape_value)
		{
			color = get_color(i);
			my_pixel_put(x, y, fractal, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, fractal, COLOR_WHITE);
}


*/