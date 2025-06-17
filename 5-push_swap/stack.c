/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:51:10 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:36 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *ft_init_stack_a(int *numbers, int total_args)
{
    t_node *stack_a;
    t_node *node;
    int i;
    
    stack_a = NULL;
    i=0;
    while(i < total_args)
    {
        node = ft_new_node(numbers[i]);
        if (!node)
        {    
            ft_free_stack(stack_a);
            return(NULL);
        }
        ft_node_add_back(&stack_a, node);
        i++;
    }
    return(stack_a);
}