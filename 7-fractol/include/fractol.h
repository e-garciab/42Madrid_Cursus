/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:44:33 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/28 20:15:05 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/X.h>

// ****SIZE****
#define WIDTH   800
#define HEIGHT  800

// ****COLORS****
#define COLOR_ELECTRIC_BLUE  0x00FFFF
#define COLOR_AZURE          0x007FFF
#define COLOR_DODGER_BLUE    0x1E90FF
#define COLOR_DEEP_SKY_BLUE  0x00BFFF
#define COLOR_CORN_FLOWER    0x6495ED
#define COLOR_ROYAL_BLUE     0x4169E1
#define COLOR_MEDIUM_SLATE   0x7B68EE
#define COLOR_SLATE_BLUE     0x6A5ACD
#define COLOR_BLUE_VIOLET    0x8A2BE2
#define COLOR_BLACK          0x000000
#define COLOR_WHITE          0xFFFFFF

// ****KEYCODES****
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 112
# define KEY_MINUS 45

// ****MOUSECODES****
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct	s_fractal
{
    char	*name;
    // **mlx**
    void	*mlx_ptr;
    void	*win_ptr;
	// **image**
    void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
    // **hooks**
    double	escape_value;
    int		max_iter;
    double	shift_x;
    double	shift_y;
    double	zoom;
    double	julia_x;
    double	julia_y;
}   t_fractal;

typedef struct	s_complex
{
	double	real;
    double	i;
}	t_complex;

typedef struct	s_range
{
	double	min;
	double	max;
}	t_range;

// ***init***
void		fractal_init(t_fractal *fractal);
void		exit_with_error(char *message);
// ***render***
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int x, int t, t_fractal *fractal);
//int			get_color(int iterations);
int			get_color(int i, t_fractal *fractal);
// ***math_utils***
double		map_value(double num, t_range old_range, t_range new_range);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		ft_atof(const char *str);
// ***hook_events***
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif /*FRACTOL_H*/
