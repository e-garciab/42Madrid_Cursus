/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:20:21 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/02 11:44:01 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_new_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

static void	ft_node_add_back(t_node **stack, t_node *new)
{
	t_node	*temp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_node	*ft_init_stack_a(int *numbers, int total_args)
{
	t_node	*stack_a;
	t_node	*node;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < total_args)
	{
		node = ft_new_node(numbers[i]);
		if (!node)
		{
			ft_free_stack(stack_a);
			return (NULL);
		}
		ft_node_add_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

void	assign_index(t_node *stack)
{
	t_node	*current;
	t_node	*min_node;
	int		index;
	int		min_value;

	index = 0;
	while (1)
	{
		current = stack;
		min_node = NULL;
		min_value = INT_MAX;
		while (current)
		{
			if (current->index == -1 && current->value < min_value)
			{
				min_value = current->value;
				min_node = current;
			}
			current = current->next;
		}
		if (!min_node)
			break ;
		min_node->index = index;
		index++;
	}
}

int	stack_size(t_node *stack_a)
{
	int	i;

	i = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}
