/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:09:26 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/27 22:19:27 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
	Mandelbrot Formula
*/
int	mandelbrot(t_pos position, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			max_iteration;

	z.reel = 0;
	z.img = 0;
	c.reel = (position.x * env->param.step) - env->param.ref.x;
	c.img = (position.y * env->param.step) - env->param.ref.y;
	// c = pos_to_complex(position, env->param);
	iter = 0;
	max_iteration = env->param.max_iter;
	while (modul_sum(z) < 4 && iter < max_iteration)
	{
		z = c_add(c_pow2(z), c);
		iter++;
	}
	return (iter);
}

/*
	Julia Formula
*/
int	julia(t_pos position, t_env *env)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			max_iteration;

	z = pos_to_complex(position, env->param);
	c = env->fractal_arg;
	iter = 0;
	max_iteration = env->param.max_iter;
	while (modul_sum(z) < 4 && iter < max_iteration)
	{
		z = c_add(c_pow2(z), c);
		iter++;
	}
	return (iter);
}

int	fractal(t_complex z, t_complex c, t_env *env)
{
	t_complex	next;
	double		reel_tmp;
	int			iter;

	iter = 0;
	next.reel = z.reel;
	next.img = z.img;
	while (next.reel * next.reel + next.img * next.img < 4 &&
		iter < env->param.max_iter)
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
void	draw_fract_ol(t_env *env, int (*color)(double, double))
{
	t_pos		pos;
	t_complex	c;
	t_complex	z;
	int			iter;

	pos.x = 0;
	c.reel = env->param.ref.x - (env->width / 2) * env->param.step;
	while (pos.x < env->width)
	{
		pos.y = 0;
		c.img = env->param.ref.y - ((env->height / 2) * env->param.step);
		while (pos.y < env->height)
		{
			z = init_complex(0, 0);
			iter = fractal(z, c, env);
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

// void	draw_fract_ol(t_env *env, int (*color)(double, double))
// {
// 	t_pos	pos;
// 	int		iter;

// 	pos.x = 0;
// 	while (pos.x < env->width)
// 	{
// 		pos.y = 0;
// 		while (pos.y < env->height)
// 		{
// 			iter = env->fractal(pos, env);
// 			if (iter == env->param.max_iter)
// 				my_mlx_pixel_put(&(env->img), pos.x, pos.y, 0x00000000);
// 			else
// 				my_mlx_pixel_put(&(env->img), pos.x, pos.y,
// 					color(iter, env->param.max_iter));
// 			pos.y++;
// 		}
// 		pos.x++;
// 	}
// }
