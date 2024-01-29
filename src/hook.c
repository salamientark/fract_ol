/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/29 07:57:48 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	draw_hud(t_env *env)
{
	mlx_string_put(env->mlx, env->window, 41, 35, 0x00EB3467, "Control Keys:");
	mlx_string_put(env->mlx, env->window, 37, 63, 0x00EB3467, "Move: ^ v < >");
	mlx_string_put(env->mlx, env->window, 37, 83, 0x00EB3467, "Zoom: C and V");
	mlx_string_put(env->mlx, env->window, 37, 103, 0x00EB3467, "Colors: 1 2 3");
	mlx_string_put(env->mlx, env->window, 37, 123, 0x00EB3467, "HUD: H");
}

/*
	Hook when key release
*/
int	handle_key_hook(int keycode, void *param)
{
	if (keycode == ARROW_RIGHT)
		((t_env *)param)->param.ref.x += (20 * ((t_env *)param)->param.step);
	if (keycode == ARROW_LEFT)
		((t_env *)param)->param.ref.x -= (20 * ((t_env *)param)->param.step);
	if (keycode == ARROW_UP)
		((t_env *)param)->param.ref.y -= (20 * ((t_env *)param)->param.step);
	if (keycode == ARROW_DOWN)
		((t_env *)param)->param.ref.y += (20 * ((t_env *)param)->param.step);
	if (keycode == V)
		((t_env *)param)->param.step *= 0.9;
	if (keycode == C)
		((t_env *)param)->param.step *= 1.1;
	if (keycode == H)
		((t_env *)param)->hud *= -1;
	if (keycode == ONE)
		((t_env *)param)->color = &purlple_palet;
	if (keycode == TWO)
		((t_env *)param)->color = &multicolor_palet;
	if (keycode == THREE)
		((t_env *)param)->color = &zoom_color;
	if (keycode == ESC)
		return (exit_fractol(((t_env *)param)));
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
	return (0);
}

/*
	Hool when nothing -> draw image
*/
int	render(t_env *env)
{
	env->img.img = mlx_new_image(env->mlx, env->width, env->height);
	if (!(env->img.img))
		return (exit_fractol(env));
	env->img.addr = mlx_get_data_addr(env->img.img, &(env->img.bits_per_pixel),
			&(env->img.line_length), &(env->img.endian));
	if (!(env->img.addr))
		return (exit_fractol(env));
	env->fractal(env, env->color);
	mlx_put_image_to_window(env->mlx, env->window, env->img.img, 0, 0);
	if (env->hud == 1)
		draw_hud(env);
	mlx_destroy_image(env->mlx, env->img.img);
	return (1);
}
