/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:23:39 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/28 12:40:10 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	get_sign(char **str)
{
	int	sign;

	sign = 1;
	while (('\t' <= **str && **str <= '\r') || **str == ' ')
		*str += 1;
	while (!ft_isdigit(**str))
	{
		if (**str == '-')
			sign *= -1;
		*str += 1;
	}
	return (sign);
}

double	ft_str_to_double(char *str)
{
	double		index;
	int			sign;
	double		nbr;

	nbr = 0;
	sign = get_sign(&str);
	while (ft_isdigit(*str))
	{
		nbr = 10 * nbr + (*str - 48);
		str++;
	}
	str += (*str && *str == '.');
	index = 10;
	while (*str && index < 100000000000000)
	{
		nbr += (*str - '0') / index;
		index *= 10;
		str++;
	}
	return (nbr * sign);
}

t_complex	init_complex(double reel, double imaginary)
{
	t_complex	c;

	c.reel = reel;
	c.img = imaginary;
	return (c);
}
