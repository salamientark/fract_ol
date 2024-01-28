/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/28 11:02:44 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/fract_ol.h"

/*
	Hook when key release
*/
int	handle_key_hook(int keycode, void *param)
{
	t_env	*env_cp;

	env_cp = (t_env *)param;
	if (keycode == ARROW_RIGHT)
		env_cp->param.ref.x += (20 * env_cp->param.step);
	if (keycode == ARROW_LEFT)
		env_cp->param.ref.x -= (20 * env_cp->param.step);
	if (keycode == ARROW_UP)
		env_cp->param.ref.y -= (20 * env_cp->param.step);
	if (keycode == ARROW_DOWN)
		env_cp->param.ref.y += (20 * env_cp->param.step);
	if (keycode == V)
	{
		env_cp->param.step *= 0.9;
		env_cp->param.step *= 0.9;
	}
	if (keycode == C)
	{
		env_cp->param.step *= 1.1;
		env_cp->param.step *= 1.1;
	}
	if (keycode == ESC)
		exit_fractol(env_cp);
	return (0);
}

void	zoom(t_env *env, int x, int y, double zoom)
{
	double	max_iter;
	double	step;

	max_iter = env->param.max_iter;
	step = env->param.step;
	env->param.ref.x += ((-(env->width / 2) + x) * step * 0.1);
	env->param.ref.y += ((-(env->height / 2) + y) * step * 0.1);
	if (zoom > 1.0)
		max_iter = fmin(MAX_ITER_UP_LIMIT, max_iter + 1);
	else
		max_iter = fmax(MAX_ITER_DOWN_LIMIT, max_iter - 1);
	if (max_iter < 10)
		max_iter = 10;
	env->param.max_iter = max_iter;
	step /= zoom;
	env->param.max_iter = max_iter;
	env->param.step = step;
}

/*
	Hook mouse
*/
int	handle_mouse_hook(int button, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (button == MOUSE_SCROLL_UP)
		zoom(env, x, y, 1.1);
	if (button == MOUSE_SCROLL_DOWN)
		zoom(env, x, y, 0.9);
	printf("max_iter = %f\n", env->param.max_iter);
	return (0);
}

/*
	Hool when nothing -> draw image
*/
int	render(t_env *env)
{
	env->img.img = mlx_new_image(env->mlx, env->width, env->height);
	if (!(env->img.img))
		exit_fractol(env);
	env->img.addr = mlx_get_data_addr(env->img.img, &(env->img.bits_per_pixel),
			&(env->img.line_length), &(env->img.endian));
	if (!(env->img.addr))
	{
		(void)mlx_destroy_image(env->mlx, env->img.img);
		exit_fractol(env);
	}
	env->fractal(env, env->color);
	mlx_put_image_to_window(env->mlx, env->window, env->img.img, 0, 0);
	mlx_destroy_image(env->mlx, env->img.img);
	return (1);
}
