/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:03:35 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/22 15:03:45 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include <../include/fractol.h>


// #include <stdio.h>

// typedef struct s_complex
// {
// 	double  real; //eje horizontal (eje x) -> eje numeros reales
//     double  i; // eje vertical (eje y) -> eje numeros imaginarios
// }	t_complex;


// int main(void)
// {
//     t_complex   z; //punto inicial (0,0)
//     t_complex   c; //punto en el mapa
//     double      tmp_real;
//     int         i = 0;

//     z.real = 0;
//     z.i = 0;
    
//     c.real = 0.25;
//     c.i = 0.4;
    
//     while(i<= 42)
//     {
//         //General formula= z² + c
//         tmp_real = (z.real * z.real) - (z.i * z.i);
//         z.i = 2 *  z.real * z.i;
//         z.real = tmp_real;
        
//         //Añadimos el valor de c
//         z.real +=c.real;
//         z.i += c.i;

//         printf("Iteration n -> %d real: %f imaginiary %f\n", i, z.real, z.i);
        
        
        
        
//         i++;
//     }

    
//     return(0);
// }