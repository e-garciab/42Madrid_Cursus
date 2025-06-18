/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_and_rev_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:07:12 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/18 18:07:14 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_node **stack, char flag)
{
    t_node *top;
    t_node *last;
    
    if(!stack || !*stack || !(*stack) -> next)
            return ;
    top = *stack;
    *stack = top -> next;
    last = *stack;
    while(last-> next)
        last=last->next;
    last->next = top;
    top -> next = NULL;     
    if(flag == 'a')
    {
        write (1, "ra\n", 3);
    }
    else if(flag == 'b')
    {
        write (1, "rb\n", 3);
    }
}

void rr_rotate (t_node **stack_a, t_node **stack_b)
{
    rotate(stack_a, 0);
    rotate(stack_b, 0);
    write(1, "rr\n", 3);
}

void reverse_rotate(t_node **stack, char flag)
{
    t_node *prev;
    t_node *last;
    
    if(!stack || !*stack || !(*stack) -> next)
            return ;
    prev = NULL;
    last = *stack;
    while(last-> next)
    {
        prev=last;
        last=last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
    if(flag == 'a')
        write (1, "rra\n", 4);
    else if(flag == 'b')
        write (1, "rrb\n", 4);
}

void rrr_reverse_rotate (t_node **stack_a, t_node **stack_b)
{
    reverse_rotate(stack_a, 0);
    reverse_rotate(stack_b, 0);
    write(1, "rrr\n", 4);
}