/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:23:39 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 22:55:11 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	return ((unsigned int) n);
}

int	rescale(int old_min, int old_max, int new_min, int new_max, double value)
{
	double	tmp_val;

	tmp_val = value / (double)(old_max - old_min);
	tmp_val *= (new_max - new_min);
	return ((int)round(tmp_val));
}
