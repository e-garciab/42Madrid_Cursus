/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:48:37 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/19 17:04:34 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <./minilibx-linux/mlx.h>

int main(void)
{
	void	*mlx_ptr;
    void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx, 800, 600, "Hello MLX in WSL!");
	mlx_loop(mlx);
	return (0);
}
