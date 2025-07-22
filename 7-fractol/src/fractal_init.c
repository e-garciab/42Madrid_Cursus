/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:38:04 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/22 16:09:50 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_ptr = mlx_init();
    if(fractal->mlx_ptr == NULL)
		ft_putstr_fd("Error setting connection", 2);
        //malloc_error();
    fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->name);
    if(fractal->win_ptr == NULL)
    {
        mlx_destroy_display(fractal->mlx_ptr);
        free(fractal->mlx_ptr);
        //malloc_error();
    }
    fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
    if(fractal->img_ptr == NULL)
    {
        mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
        mlx_destroy_display(fractal->mlx_ptr);
        free(fractal->mlx_ptr);
        //malloc_error();
    }
    fractal->addr =  mlx_get_data_addr(fractal->img_ptr, &fractal->bpp, &fractal->line_len, &fractal->endian); //¿¿¿POR QUÉ BPP, LINE_LEN Y ENDIAN VAN POR REFERENCIA &????
    //events_init(fractal);
    //dta_init(fractal);
}