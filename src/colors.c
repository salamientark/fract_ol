/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:22 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/28 10:54:10 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	make_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	purlple_palet(double iter, double max_iter)
{
	int		red;
	int		blue;
	int		green;
	double	tmp;

	red = rescale(0, max_iter, 0, 255, max_iter - iter);
	tmp = (double)ft_abs(cos(iter / max_iter - M_PI) - 1) / 2;
	blue = (rescale(0, max_iter, 0, 255, tmp * max_iter));
	tmp = (double)(sin((-iter) / max_iter));
	green = (rescale(0, max_iter, 0, 255, (tmp * tmp) / max_iter));
	return (make_color(0, red, green, blue));
}
