/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:25:57 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/23 12:36:16 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
    ____x=800____
    |           |           
    |           y=800
    |           |
    |___________| 
    
*/
/*
MANDELBROT:
z = Z^2 + c; 
z initially is (0,0)
c is the pointer to the addres of the pixel
*/

static int get_color(int iterations)
{
    int colors[] = {COLOR_ELECTRIC_BLUE, COLOR_AZURE, COLOR_DODGER_BLUE,
        COLOR_DEEP_SKY_BLUE, COLOR_CORN_FLOWER, COLOR_ROYAL_BLUE,
        COLOR_MEDIUM_SLATE, COLOR_SLATE_BLUE, COLOR_BLUE_VIOLET};
        
	int size;
	int index;

    size = sizeof(colors) / sizeof(colors[0]);
    index = iterations;
	while (index >= size)
		index -= size;
	return (colors[index]);
}


static void my_pixel_put(int x, int y, t_fractal *fractal, int color)
{
    int offset;
    
    offset = (y * fractal->line_len) + (x * (fractal->bpp / 8));
    *(unsigned int *)(fractal->addr + offset) = color;
}


void    handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex   z;
    t_complex   c;
    t_range     old_range;
    t_range     new_range;
    int         i;
    int color;

    i=0;
    old_range.min = 0;
    old_range.max = WIDTH;
    new_range.min = -2.0;
    new_range.max = +2.0;
    c.real = map_value(x, old_range, new_range) + fractal->shift_x;

    old_range.min = 0;
    old_range.max = HEIGHT;
    new_range.min = +2.0;
    new_range.max = -2.0;
    c.i = map_value(y, old_range, new_range) + fractal->shift_y;
    
    z.real = 0.0;
    z.i = 0.0;
       
    while(i < fractal->iteration_definition) //¿cuantas veces tiene que iterar z^2 + c para ver si el punto se escapa?
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


void    fractal_render(t_fractal *fractal)
{
    int x; 
    int y; 
    
    y = 0; // ¿¿POR QUÉ -1 Y NO 0??
    while(y < HEIGHT)
    {
        x = 0;
        while(x < WIDTH)
        {
            handle_pixel(x, y, fractal);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window (fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
}