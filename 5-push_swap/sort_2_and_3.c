/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_and_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:03:48 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/02 11:54:33 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, 'a');
}

void	sort_3(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first < second && second > third && first < third) // caso 1: 1 3 2
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (first > second && second < third && first < third) // caso 2: 2 1 3
		swap(stack_a, 'a');
	else if (first < second && second > third && first > third) // caso 3: 2 3 1
		reverse_rotate(stack_a, 'a');
	else if (first > second && second > third) // caso 4: 3 2 1
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
	else if (first > second && second < third && first > third) // caso 5: 3 1 2
		rotate(stack_a, 'a');
}
