/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:20:21 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:38 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_node_add_back(t_node **stack, t_node *new)
{
	t_node *temp; 
	if(!stack || !new)
		return ;
	if(!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack; 
	while(temp->next != NULL)
		temp = temp -> next;
	temp -> next = new;
}





