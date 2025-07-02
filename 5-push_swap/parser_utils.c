/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:49:00 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/02 11:42:38 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static int	ft_check_limits(long result, int sign)
{
	if ((sign == 1 && result > INT_MAX) || (sign == -1 && result > (long)INT_MAX
			+ 1))
	{
		return (0);
	}
	return (1);
}

int	ft_atoi_safe(char *str, int *out)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	if (!str || str[0] == '\0')
		return (0);
	while ((str[i]) && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	sign = ft_check_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (!ft_check_limits(result, sign))
			return (0);
		i++;
	}
	*out = (int)(result * sign);
	return (1);
}

int	ft_has_duplicates(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
