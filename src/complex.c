/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:01:11 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 22:52:45 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double	modul_sum(t_complex c)
{
	return (c.reel * c.reel + c.img * c.img);
}

t_complex	init_complex(double reel, double imaginary)
{
	t_complex	c;

	c.reel = reel;
	c.img = imaginary;
	return (c);
}

t_complex	c_add(t_complex c1, t_complex c2)
{
	t_complex	c_final;

	c_final.reel = c1.reel + c2.reel;
	c_final.img = c1.img + c2.img;
	return (c_final);
}

t_complex	c_pow2(t_complex c)
{
	t_complex	c_pow;

	c_pow.reel = c.reel * c.reel - (c.img * c.img);
	c_pow.img = 2 * c.reel * c.img;
	return (c_pow);
}

t_complex	pos_to_complex(t_pos pos, t_param param)
{
	t_complex	c;
	double		middle_line;
	double		middle_col;
	double		final_zoom;

	middle_line = (double) param.ref.y;
	middle_col = (double) param.ref.x;
	final_zoom = middle_line * param.zoom;
	c.reel = ((double)pos.y - (double)param.offset.y - middle_col) / final_zoom;
	c.img = ((double)pos.x - (double)param.offset.x - middle_line) / final_zoom;
	return (c);
}
