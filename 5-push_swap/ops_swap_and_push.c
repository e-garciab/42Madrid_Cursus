/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap_and_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:04:46 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/18 18:11:57 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_node **stack, char flag)
{
    t_node *first;
    t_node *second;
    
    if(!stack || !*stack ||!(*stack) -> next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    if(flag == 'a')
        write(1, "sa\n", 3);
    if(flag == 'b')
        write(1, "sb\n", 3);
    
}

void ss_swap (t_node **stack_a, t_node **stack_b)
{
    swap(stack_a, 0);
    swap(stack_b, 0);
    write(1, "ss\n", 3);
}

void push(t_node **stack_a, t_node **stack_b, char flag)
{
    t_node *top_src;
    if(flag == 'a')
    {
        if(!stack_b || !*stack_b || !(*stack_b) -> next)
            return ;
        top_src = *stack_b;
        *stack_b = top_src->next;
        top_src -> next = *stack_a;
        *stack_a = top_src;
        write (1, "pa\n", 3);
    } 
    else if(flag == 'b')
    {
        if(!stack_a || !*stack_a || !(*stack_a) -> next)
            return ;
        top_src = *stack_a;
        *stack_a = top_src->next;
        top_src -> next = *stack_b;
        *stack_b = top_src;
        write (1, "pb\n", 3);
    }
}

