/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_and_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:22:44 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/27 17:52:42 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min_position (t_node *stack_a)
{
    t_node *temp;
    int min; 
    int pos;
    int i;

    if(!stack_a)
        return(0);
    temp = stack_a;
    min = stack_a->value;
    pos = 0;
    i= 0;
    while(temp)
    {
        if(temp-> value < min)
        {
            min= temp->value;
            pos = i;
        }
        temp=temp->next;
        i++;
    }
    return(pos);
}

static void move_min_to_top (t_node **stack_a)
{
    int size;
    int pos;
    
    if(!stack_a || !*stack_a)
        return;
    size = stack_size (*stack_a);
    pos = find_min_position(*stack_a);
    if(pos <= (size / 2))
    {
        while(pos--)
            rotate(stack_a, 'a');
    }
    else
    {
        pos = size-pos;
        while(pos--)
            reverse_rotate(stack_a, 'a');
    }         
}

void sort_4 (t_node **stack_a, t_node **stack_b)
{
    move_min_to_top(stack_a);
    push(stack_a, stack_b, 'b');
    sort_3(stack_a);
    push(stack_a, stack_b, 'a');
}

void sort_5 (t_node **stack_a, t_node **stack_b)
{
    move_min_to_top(stack_a);
    push(stack_a, stack_b, 'b');
    move_min_to_top(stack_a);
    push(stack_a, stack_b, 'b');
    sort_3(stack_a);
    if((*stack_b)-> value < (*stack_b)->next->value)
        swap(stack_b, 'b');
    push(stack_a, stack_b, 'a');
    push(stack_a, stack_b, 'a');
}