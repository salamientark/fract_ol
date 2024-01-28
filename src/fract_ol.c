/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:09:26 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/28 08:13:34 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static int	fractal(t_complex z, t_complex c, int max_iter)
{
	t_complex	next;
	double		reel_tmp;
	int			iter;

	iter = 0;
	next.reel = z.reel;
	next.img = z.img;
	while (next.reel * next.reel + next.img * next.img < 4 &&
		iter < max_iter)
	{
		reel_tmp = next.reel;
		next.reel = next.reel * next.reel - next.img * next.img + c.reel;
		next.img = 2 * reel_tmp * next.img + c.img;
		iter++;
	}
	return (iter);
}

/*
	Draw_fractal to image in env
*/
void	mandelbrot(t_env *env, int (*color)(double, double))
{
	t_pos		pos;
	t_complex	c;
	int			iter;

	pos.x = 0;
	c.reel = env->param.ref.x - (env->width / 2) * env->param.step;
	while (pos.x < env->width)
	{
		pos.y = 0;
		c.img = env->param.ref.y - ((env->height / 2) * env->param.step);
		while (pos.y < env->height)
		{
			iter = fractal(init_complex(0, 0), c, env->param.max_iter);
			if (iter == env->param.max_iter)
				my_mlx_pixel_put(&(env->img), pos.x, pos.y, 0x00000000);
			else
				my_mlx_pixel_put(&(env->img), pos.x, pos.y,
					color(iter, env->param.max_iter));
			pos.y++;
			c.img += env->param.step;
		}
		pos.x++;
		c.reel += env->param.step;
	}
}

/*
	Julia fractal drawing
*/
void	julia(t_env *env, int (*color)(double, double))
{
	t_pos		pos;
	t_complex	c;
	int			iter;

	pos.x = 0;
	c.reel = env->param.ref.x - (env->width / 2) * env->param.step;
	while (pos.x < env->width)
	{
		pos.y = 0;
		c.img = env->param.ref.y - ((env->height / 2) * env->param.step);
		while (pos.y < env->height)
		{
			iter = fractal(c, env->fractal_arg, env->param.max_iter);
			if (iter == env->param.max_iter)
				my_mlx_pixel_put(&(env->img), pos.x, pos.y, 0x00000000);
			else
				my_mlx_pixel_put(&(env->img), pos.x, pos.y,
					color(iter, env->param.max_iter));
			pos.y++;
			c.img += env->param.step;
		}
		pos.x++;
		c.reel += env->param.step;
	}
}
