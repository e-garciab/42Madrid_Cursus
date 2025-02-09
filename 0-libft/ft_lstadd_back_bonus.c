/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:32:52 by marvin            #+#    #+#             */
/*   Updated: 2025/02/09 18:32:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief add the 'new' node at the end of the list 'lst'
/// @param lst the pointer address to the first node in the list
/// @param  new the pointer address to the new node to add to the list
/// @return none
void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list  *last;

    last = ft_lstlast(*lst);
    if (!last)
        *lst = new;
    last->next = new;
}


int	main(void)
{
	t_list	*first;
	t_list	*second;
    t_list	*new;
	t_list	*last;

	first = ft_lstnew("Nodo 1");
	second = ft_lstnew("Nodo 2");
	new = ft_lstnew("Nodo Nuevo");
	first->next = second;
	second->next = NULL;

    last = ft_lstlast_back(first, new);
	printf("Result: %s\n", (char *)last->content);
	free(first);
	free(second);
	free(new);
	return (0);
}
