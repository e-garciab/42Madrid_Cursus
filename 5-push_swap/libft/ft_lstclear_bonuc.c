/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonuc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:30:36 by marvin            #+#    #+#             */
/*   Updated: 2025/02/09 23:30:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief  Deletes and free the memory of the element passed as parameter 
/// and all the following elements using 'del' and free(3). 
/// Finally, the initial pointer must be set to NULL.
/// @param lst pointer address to one element
/// @param del address of the function that can delete the element's content
/// @return none 
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    while (*lst != NULL)
    {    
        del ((*lst)->content);
        lst = lst->next;
    }
    free (lst);
    *lst = NULL;
}