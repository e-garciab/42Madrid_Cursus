/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:30:56 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 17:33:59 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node *stack)
{
	t_node *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int main(int argc, char *argv[])
{
	int *numbers;
	int total_args;
	t_node *stack_a;
	t_node *temp;
	
	if(argc<2)
		return(0);
	numbers = parse_args(argc, argv, &total_args);
	if(!numbers)
		return(1);
	stack_a = ft_init_stack_a(numbers, total_args);
	if(!stack_a)
	{
		free(numbers);
		write(2, "Error\n", 6);
		return (1);
	}
	// solo para verificacion
	temp = stack_a;
	while(temp)
	{
		printf("Antes: %d\n", temp->value);
		temp = temp -> next;
	}
	temp = 	sa_swap_a(stack_a);
	while(temp)
	{
		printf("Despues: %d\n", temp->value);
		temp = temp -> next;
	}
	free(numbers);
	ft_free_stack(stack_a);
	return (0);
}
