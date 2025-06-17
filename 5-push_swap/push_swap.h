/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:30:12 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 17:34:03 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node {
	int	value;
	int	index;
	struct s_node *next;
} t_node;


typedef struct s_stack_set
{
	t_list	*a;
	t_list	*b;
}			t_stack_set;


void ft_free_split(char **split);
int ft_is_valid_number(char *str);
int ft_atoi_safe(char *str, int *out);
int	ft_has_duplicates(int *array, int len);
int ft_count_total_args(int argc, char *argv[]);
char **get_args(int argc, char *argv[], int *total_args);
int *parse_args(int argc, char *argv[], int *total_args);
int main(int argc, char *argv[]);
void	ft_free_stack(t_node *stack);
t_node	*ft_new_node(int value);
void	ft_node_add_back(t_node **stack, t_node *new);
t_node *ft_init_stack_a(int *numbers, int total_args);


//MOVEMENTS
void sa_swap_a(t_node **stack_a);  // Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 
void sb_swap_b(t_node **stack_b);  // Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 
void ss_swap_ab(t_node **stack_a, t_node **stack_b); // sa and sb at the same time. 

void pa_push_a(t_node **stack_a, t_node **stack_b); // push top de b a a. Takes the first element on top of b and puts it on a. Does nothing if b is empty. 
void pb_push_b(t_node **stack_a, t_node **stack_b); // push top de a a b. Takes the first element on top of a and puts it on b. Does nothing if a is empty. 

void ra_rotate_a(t_node **stack_a); // rotate up stack a. Shifts all the elements of the stack a up by one position. The first element becomes the last. 
void rb_rotate_b(t_node **stack_b); // rotate up stack b. Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 
void rr_rotate_ab(t_node **stack_a, t_node **stack_b); // ra y rb simultáneo

void rra_reverse_rotate_a(t_node **stack_a); // rotate down stack a. Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 
void rrb_reverse_rotate_b(t_node **stack_b); // rotate down stack b. Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 
void rrr_reverse_rotate_ab(t_node **stack_a, t_node **stack_b); // rra y rrb simultáneo









#endif /*PUSH_SWAP_H*/