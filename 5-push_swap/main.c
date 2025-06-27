/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:30:56 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/27 19:37:41 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_sorted(t_node *stack_a)
{
	if(!stack_a || !stack_a->next)
		return(1);
	while(stack_a && stack_a->next)
	{
		if(stack_a->value > stack_a->next->value)
			return(0); 
		stack_a = stack_a -> next;
	}
	return(1);
}

static void select_sort_method(t_node **stack_a, t_node **stack_b, int total_args)
{
    int size; 

    size = stack_size(*stack_a);
    if(size == 2)
        sort_2(stack_a);
    else if(size == 3)
        sort_3(stack_a);
    else if(size == 4)
        sort_4(stack_a, stack_b);
    else if(size == 5)
        sort_5(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b, total_args);
}
//SOLO PARA VERIFICACION; SE PUEDE BORRAR ANTES DE ENTREGAR
void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("Value: %d | Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
}

static int init_program(int argc, char *argv[], t_node **stack_a, t_node **stack_b)
{
	int total_args;
	int *numbers;
	
	total_args = count_total_args(argc, argv);
	numbers = parse_args(argc, argv, total_args);
	if(!numbers)
		return(0);
	*stack_a = ft_init_stack_a(numbers, total_args);
	free(numbers);
	if(!*stack_a)
	{
		write(2, "Error\n", 6);
		ft_free_stack(*stack_a);
		return (0);
	}
	*stack_b = NULL;
	return(1);
}
int main(int argc, char *argv[])
{
	t_node *stack_a;
	t_node *stack_b;

	if(argc<2)
		return(0);
	if(!init_program(argc, argv, &stack_a, &stack_b))
		return(1);
	if(is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		return(0);
	}
	assign_index(stack_a);
	//select_sort_method(&stack_a, &stack_b, count_total_args(argc, argv));
	
	// // SOLO PARA VERIFICACIÓN:
	// // mostrar valores originales
	printf("Antes stack A: \n");
	print_stack(stack_a);
	printf("Antes stack B: \n");
	print_stack(stack_b);
	printf("-----------------\n");
	
	select_sort_method(&stack_a, &stack_b, count_total_args(argc, argv));	
	printf("-----------------\n");

	printf("Después stack A: \n");
	print_stack(stack_a);
	printf("Después stack B: \n");
	print_stack(stack_b);
	printf("-----------------\n");
	
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
