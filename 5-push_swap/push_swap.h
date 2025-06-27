/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:30:12 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/27 17:43:32 by egarcia2         ###   ########.fr       */
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
	int	value; //valor original
	int	index; //valor del índice
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}			t_stack;

int main(int argc, char *argv[]);
void ft_free_split(char **split);
int count_total_args(int argc, char *argv[]);
int *parse_args(int argc, char *argv[], int total_args);
int ft_is_valid_number(char *str);
int ft_atoi_safe(char *str, int *out);
int	ft_has_duplicates(int *array, int len);
t_node *ft_init_stack_a(int *numbers, int total_args);
void assign_index(t_node *stack);
int stack_size (t_node *stack_a);
void ft_free_stack(t_node *stack);
void swap(t_node **stack, char flag);
void ss_swap (t_node **stack_a, t_node **stack_b);
void push(t_node **stack_a, t_node **stack_b, char flag);
void rotate(t_node **stack, char flag);
void rr_rotate (t_node **stack_a, t_node **stack_b);
void reverse_rotate(t_node **stack, char flag);
void rrr_reverse_rotate (t_node **stack_a, t_node **stack_b);
void sort_2 (t_node **stack_a);
void sort_3 (t_node **stack_a);
void sort_4 (t_node **stack_a, t_node **stack_b);
void sort_5 (t_node **stack_a, t_node **stack_b);
void radix_sort(t_node **stack_a, t_node **stack_b, int total_args);


// void ft_free_split(char **split);
// int ft_is_valid_number(char *str);
// int ft_atoi_safe(char *str, int *out);
// int	ft_has_duplicates(int *array, int len);
// int ft_count_total_args(int argc, char *argv[]);
// char **get_args(int argc, char *argv[], int *total_args);
// int *parse_args(int argc, char *argv[], int *total_args);
// int main(int argc, char *argv[]);
// void	ft_free_stack(t_node *stack);
// t_node	*ft_new_node(int value);
// void	ft_node_add_back(t_node **stack, t_node *new);
// t_node *ft_init_stack_a(int *numbers, int total_args);
// void assign_index(t_node *stack);
// void radix_sort(t_node **stack_a, t_node **stack_b, int total_args);
// int is_sorted(t_node *stack_a);


#endif /*PUSH_SWAP_H*/