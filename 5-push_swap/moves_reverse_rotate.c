/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:47:11 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 17:34:07 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rra_reverse_rotate_a(t_node **stack_a); // rotate down stack a. Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 
void rrb_reverse_rotate_b(t_node **stack_b); // rotate down stack b. Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 
void rrr_reverse_rotate_ab(t_node **stack_a, t_node **stack_b); // rra y rrb simultáneo