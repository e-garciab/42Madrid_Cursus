/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:21:53 by egarcia2          #+#    #+#             */
/*   Updated: 2026/03/22 20:18:03 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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

int	ft_atoi_safe(char *str, long *out)
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
	*out = (result * sign);
	return (1);
}

int	exit_error(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(2, str, len);
	return (1);
}
