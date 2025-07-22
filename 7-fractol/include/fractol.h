/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:44:33 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/22 15:52:32 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdio.h> //debugging
# include <stdlib.h> // malloc free
# include <unistd.h> //write
# include <mlx.h> //minilibx


#define WIDTH   800
#define HEIGHT  800

typedef struct s_fractal
{
    char    *name;
    // **MLX**
    void	*mlx_ptr; //pointer that results from mlx_init
    void	*win_ptr; //pointer that results from mlx_new_window
	// **Image**
    void	*img_ptr; //pointer that results from mlx_new_image (pointer to image struct)
	char	*addr; //pointer that results from mlx_get_data_addr (pointer to the actual pixel)
	int		bpp; //cuantos bits por pixel (pixel->int->4bytes->32bits)
	int		line_len;
	int		endian;
    // **Hooks member variables**
}   t_fractal;


#endif /*FRACTOL_H*/