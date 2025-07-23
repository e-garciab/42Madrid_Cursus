/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:44:33 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/23 14:04:31 by egarcia2         ###   ########.fr       */
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
# include <X11/X.h>

#define WIDTH   800
#define HEIGHT  800

// ****COLORS****
// Colores psicodélicos brillantes
#define COLOR_ELECTRIC_BLUE  0x00FFFF  // Cyan brillante
#define COLOR_AZURE          0x007FFF  // Azul brillante intenso
#define COLOR_DODGER_BLUE    0x1E90FF  // Azul vivo y saturado
#define COLOR_DEEP_SKY_BLUE  0x00BFFF  // Azul cielo profundo
#define COLOR_CORN_FLOWER    0x6495ED  // Azul suave y luminoso
#define COLOR_ROYAL_BLUE     0x4169E1  // Azul real vibrante
#define COLOR_MEDIUM_SLATE   0x7B68EE  // Azul pizarra medio
#define COLOR_SLATE_BLUE     0x6A5ACD  // Azul pizarra clásico
#define COLOR_BLUE_VIOLET    0x8A2BE2  // Violeta azul eléctrico
#define COLOR_BLACK          0x000000  // Para contraste oscuro
#define COLOR_WHITE          0xFFFFFF 


// ****KEYCODES****
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 112
# define KEY_MINUS 45

# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOW

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
    double  escape_value; // hypothenuse
    int     iteration_definition;
    double  shift_x;
    double  shift_y;
}   t_fractal;

typedef struct s_complex
{
	double  real; //eje horizontal (eje x) -> eje numeros reales
    double  i; // eje vertical (eje y) -> eje numeros imaginarios
}	t_complex;

typedef struct s_range
{
	double min;
	double max;
}	t_range;

// ***init***
void    fractal_init(t_fractal *fractal);
// ***render***
void    fractal_render(t_fractal *fractal);
void    handle_pixel(int x, int t, t_fractal *fractal);
// ***math*** ->LINEAR INTERPOLATION - PARA RESCALAR - MIRAR Y CAMBIAR LA FUNCIÓN.
double	map_value(double num, t_range old_range, t_range new_range);
t_complex   sum_complex(t_complex z1, t_complex z2);
t_complex   square_complex(t_complex z);
// ***hook_events***
int key_handler(int keycode, t_fractal *fractal);
int    close_handler(t_fractal *fractal);


#endif /*FRACTOL_H*/