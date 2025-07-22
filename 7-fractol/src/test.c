/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:48:37 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/22 16:01:25 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <../include/fractol.h>

int main(void)
{
	void	*mlx_ptr;
    void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		x; //eje horizontal
	int		y; // eje vertical

	int		width = 800;
	int		height = 600;

	mlx_ptr = mlx_init();
	if(mlx_ptr == NULL)
		ft_putstr_fd("Error setting connection", 2);
	win_ptr = mlx_new_window(mlx_ptr, width, height, "Hello MLX in WSL!");
	img_ptr = mlx_new_image(mlx_ptr, width, height);
    mlx_pixel_put (mlx_ptr, win_ptr, width/2, height/2, 0x00FF00);
    addr = mlx_get_data_addr(img_ptr, &bpp, &line_len, &endian);
    ft_printf("Dirección: %p", addr);
 
    //mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

	
	mlx_loop(mlx_ptr);
	return (0);
}
