/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:50:08 by egarcia2          #+#    #+#             */
/*   Updated: 2025/06/17 16:22:47 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_split(char **split)
{
	int i;
	i=0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
