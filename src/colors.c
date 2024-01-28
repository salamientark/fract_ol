/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:22 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/28 12:41:19 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	rescale(int old_min, int old_max, double value)
{
	double	tmp_val;

	tmp_val = value / (double)(old_max - old_min);
	tmp_val *= 255;
	return ((int)round(tmp_val));
}

int	purlple_palet(double iter, double max_iter)
{
	int		red;
	int		blue;
	int		green;
	double	tmp;

	red = rescale(0, max_iter, max_iter - iter);
	tmp = (double)ft_abs(cos(iter / max_iter - M_PI) - 1) / 2;
	blue = (rescale(0, max_iter, tmp * max_iter));
	tmp = (double)(sin((-iter) / max_iter));
	green = (rescale(0, max_iter, (tmp * tmp) / max_iter));
	return (0 << 24 | red << 16 | green << 8 | blue);
}

int	multicolor_palet(double iter, double max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = iter / max_iter;
	r = (int)(sin(2 * M_PI * t + 0) * 127 + 128);
	g = (int)(sin(2 * M_PI * t + 2) * 127 + 128);
	b = (int)(sin(2 * M_PI * t + 4) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}
