/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:44:35 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/02 12:00:35 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b, int total_args)
{
	int	i;
	int	j;
	int	max_index; // máximo índice que vas a tener en tu stack, el index va de 0 a n-1
	int	max_bits; // cantidad de bits que necesitas para representar ese número (cuántod digitos binarios tiene)

	max_index = total_args - 1; // porque index empieza en 0
	max_bits = 0;
	i = 0;
	while (max_index >> max_bits != 0) // se van desplazando los bits de max_index tantas posiciones como valga max_bits
		max_bits++;
	while (i < max_bits) //voy a ir recorriendo bit a bit desde bit 0 (el menos significativo, la derecha) a max_bits (más sigificativo, la izquierda)
	{
		j = 0;
		while (j < total_args) // para cada bit, voy a recorrer todos los elementos del stack a
		{
			if (((*stack_a)->index >> i) & 1) // Para cada nodo en stack_a, desplaza el índice i bits a la derecha.&1 saca solo el bit menos significativo (bit i original).
				rotate(stack_a, 'a'); //si el bit menos significativo es 1, muevo  el nodo al final de stack A.
			else
				push(stack_a, stack_b, 'b'); // si es 0, lo muevo a stack b
			j++;
		}
		while (*stack_b) // tras procesar todos los elementos de se bit, // lo pusheo todo a 'a' de nuevo.
			push(stack_a, stack_b, 'a');
		i++;
	}
}
