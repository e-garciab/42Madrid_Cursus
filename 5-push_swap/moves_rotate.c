/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:46:44 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 17:34:12 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ra_rotate_a(t_node **stack_a); // rotate up stack a. Shifts all the elements of the stack a up by one position. The first element becomes the last. 
void rb_rotate_b(t_node **stack_b); // rotate up stack b. Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 
void rr_rotate_ab(t_node **stack_a, t_node **stack_b); // ra y rb simultáneo