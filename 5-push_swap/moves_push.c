/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:46:20 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 17:34:18 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void pa_push_a(t_node **stack_a, t_node **stack_b); // push top de b a a. Takes the first element on top of b and puts it on a. Does nothing if b is empty. 
void pb_push_b(t_node **stack_a, t_node **stack_b); // push top de a a b. Takes the first element on top of a and puts it on b. Does nothing if a is empty. 
