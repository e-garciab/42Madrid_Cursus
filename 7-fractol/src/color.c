/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:49:36 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/28 20:17:06 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	get_color(int iterations)
// {
// 	int	colors[] = {COLOR_ELECTRIC_BLUE, COLOR_AZURE, COLOR_DODGER_BLUE,
// 			COLOR_DEEP_SKY_BLUE, COLOR_CORN_FLOWER, COLOR_ROYAL_BLUE,
// 			COLOR_MEDIUM_SLATE, COLOR_SLATE_BLUE, COLOR_BLUE_VIOLET};
// 	int	size;
// 	int	index;

// 	size = sizeof(colors) / sizeof(colors[0]);
// 	index = iterations;
// 	while (index >= size)
// 		index -= size;
// 	return (colors[index]);
// }

int get_color(int i, t_fractal *fractal)
{
	double t;
    int r;
    int g;
    int b;
    
    t = (double)i / fractal->max_iter;
	r = (int)(0 * (1 - t) + 0 * t);
	g = (int)(20 * (1 - t) + 255 * t);
	b = (int)(50 * (1 - t) + 255 * t);
	return ((r << 16) | (g << 8) | b);
}