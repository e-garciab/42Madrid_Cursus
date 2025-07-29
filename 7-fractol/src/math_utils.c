/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egarcia2 <egarcia2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:51:57 by egarcia2          #+#    #+#             */
/*   Updated: 2025/07/28 19:01:03 by egarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map_value(double num, t_range old_range, t_range new_range)
{
	return ((new_range.max - new_range.min) * (num - old_range.min)			
    / (old_range.max - old_range.min) + new_range.min);	
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.real = z1.real + z2.real;
	result.i = z1.i + z2.i;
	return (result);
}

t_complex square_complex(t_complex z)
{
	t_complex result;

	result.real = (z.real * z.real) - (z.i * z.i);
	result.i = 2 * z.real * z.i;
	return (result);
}

static void	ft_decimal_part(const char *str, int *i, double *result)
{
	double	decimal;
	
	decimal = 0.1;
    (*i)++;
    while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result += (str[*i] - '0') * decimal;
        decimal *= 0.1;
		(*i)++;
	}
}

double	ft_atof(const char *str)
{
	int	i;
	double	result;
	int	sign;

	i = 0;
	result = 0.0;
	sign = 1;
    while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0.0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		ft_decimal_part(str, &i, &result);
	return (result * sign);
}
