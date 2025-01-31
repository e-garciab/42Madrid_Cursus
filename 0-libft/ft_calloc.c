/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:07:37 by marvin            #+#    #+#             */
/*   Updated: 2025/01/29 19:07:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;

    ptr = malloc (nmemb * size);
    if (ptr == NULL)
        return (NULL);
    memset (ptr, 0, nmemb * size);
    return (ptr);
}

int main(void)
{
    int *arr1 = calloc(10, sizeof(int));
    printf("%d\n", *arr1);
    int *arr2 = ft_calloc(10, sizeof(int));
    printf("%d\n", *arr2);
    return (0);
}