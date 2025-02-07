/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:00:01 by egarcia2          #+#    #+#             */
/*   Updated: 2025/02/07 16:25:42 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief Adds the node 'new' to the beginning of the list 'lst'.
/// @param lst pointer address to the first element of the list.
/// @param  new pointer address of the new element to add to the front of the 
/// list.
/// @return none
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/* REVISAR MAIN  DA CORE DUMP
int	main(void)
{
	t_list	*old;
	t_list	*new;

	old = ft_lstnew("Nodo 1");
	new = ft_lstnew("Nodo 2");
	
	old->next = new;
	new->next = NULL;
	
	ft_lstadd_front(&old, new);
	printf("Result: %s\n", (char *)old->content);
	
	free(old);
	free(new);
	return (0);
}
*/