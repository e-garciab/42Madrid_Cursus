/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:46:03 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 17:34:09 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void sa_swap_a(t_node **stack_a);  // Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 
void sb_swap_b(t_node **stack_b);  // Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 
void ss_swap_ab(t_node **stack_a, t_node **stack_b); // sa and sb at the same time. 

void sa_swap_a(t_node **stack_a)
{
    t_node *first;
    t_node *second;
    
    if(!stack_a || !*stack_a ||!(*stack_a) -> next)
        return ;

    first = *stack_a;
    second = first->next;
    
    first->next = second->next;
    second->next = first;
    *stack_a = second;
}

void sb_swap_b(t_node **stack_b)
{
    t_node *first;
    t_node *second;
    
    if(!stack_b || !*stack_b ||!(*stack_b) -> next)
        return ;

    first = *stack_b;
    second = first->next;
    
    first->next = second->next;
    second->next = first;
    *stack_b = second;
}
void ss_swap_ab(t_node **stack_a, t_node **stack_b)
{

    
}
