/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:30:54 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/23 11:23:51 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.RENDERIZADO:
• Dos conjuntos: Julia y Mandelbrot.
• La rueda del ratón hace zoom in y zoom out y lo hace casi infinitamente.
• Debe recibir parametros para crear un conjunto de Julia diferente .
• Un parámetro se pasará a través de la CLI para definir el tipo de fractal visualizado.
	• Puedes usar más parámetros como opciones de renderizado.
	• Si no se introduce un parámetro, o si el parámetro es inválido,
		el programa
mostrará una lista de parámetros disponibles y terminará correctamente.
• Debes usar al menos unos pocos colores para mostrar la profundidad de cada
fractal.
2.REPRESENTACION GRAFICA:
• Tu programa tiene que mostrar la imagen en una ventana.
• El manejo de tu ventana debe ser fluido (cambio a otra ventana, minimización y
demás)
• ESC debe cerrar la ventana y salir del programa de manera limpia. NO LEAKS!!
• Hacer click en la cruz del marco de la ventana debe cerrarla y cerrar el programa
de manera limpia.
• El uso de images de la MiniLibX es obligatorio.
*/


#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal   fractal;
    // dos alternativas de args:
	//     ./fractol mandelbrot
	//     ./fractol julia <real> <imaginary>
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 6)))
	{
		// ARGS CORRECTOS, LANZA EL PROGRAMA
        fractal.name = argv[1];
		if (fractal.name == NULL)
		{ //DEBUG
			ft_putstr_fd("fractal->name is NULL\n", 2);
		}//DEBUG
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
