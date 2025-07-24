/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:30:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/24 19:29:42 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.RENDERIZADO:
• Dos conjuntos: Julia - TO DO
• La rueda del ratón hace zoom in y zoom out y lo hace casi infinitamente.
	- TO DO
• Debe recibir parametros para crear un conjunto de Julia diferente - TO DO
• Puedes usar más parámetros como opciones de renderizado.
2.REPRESENTACION GRAFICA:
• El manejo de tu ventana debe ser fluido (cambio a otra ventana, minimización y
demás)
• El uso de images de la MiniLibX es obligatorio.
*/

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	// dos alternativas de args:
	//     ./fractol mandelbrot
	//     ./fractol julia <real> <imaginary>
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 6)))
	{
		// ARGS CORRECTOS, LANZA EL PROGRAMA
		fractal.name = argv[1];
        printf("fractal name: %s\n", fractal.name);
        if (fractal.name == NULL)
		// DEBUG
			ft_putstr_fd("fractal->name is NULL\n", 2);
        // DEBUG
		if(fractal.name == 'julia')
        {
            fractal.julia_x = ft_atof(argv[2]);
            printf("fractal julia x: %p\n", fractal.julia_x);
		    fractal.julia_y = ft_atof(argv[3]);
        }
		// 1)Inicializar programa
		fractal_init(&fractal);
		// 2) Renderizdo en la ventana
		fractal_render(&fractal);
		// 3) Gestion eventos
		mlx_loop(fractal.mlx_ptr);
	}
	else
	{
		// ARGS INCORRECTOS. MOSTRAR LISTA DE PARAMETROS DISPONIBLES Y SALIR
		ft_putstr_fd("Invalid arguments. Please enter:\n\t 1) \"./fractol mandelbrot\" or \n\t 2) \"./fractol julia <real value> <imaginary value>\"\n",
			2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
