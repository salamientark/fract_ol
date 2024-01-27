/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/27 20:18:47 by dbaladro         ###   ########.fr       */
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
	else if (keycode == ARROW_LEFT)
		env_cp->param.ref.x -= (20 * env_cp->param.step);
	else if (keycode == ARROW_UP)
		env_cp->param.ref.y -= (20 * env_cp->param.step);
	else if (keycode == ARROW_DOWN)
		env_cp->param.ref.y += (20 * env_cp->param.step);
	else if (keycode == V)
	{
		env_cp->param.step *= 0.9;
		env_cp->param.step *= 0.9;
	}
	else if (keycode == C)
	{
		env_cp->param.step *= 1.1;
		env_cp->param.step *= 1.1;
	}
	else if (keycode == ESC)
		exit_fractol(env_cp);
	else
		return (ft_printf("%d\n", keycode));
	// env_cp->param.step /= env_cp->param.zoom;
	return (0);
}

/*
	Hook mouse
*/
int	handle_mouse_hook(int button, int x, int y, void *param)
{
	t_env	*env;

	(void) x;
	(void) y;
	(void) button;
	env = (t_env *)param;
	if (button == MOUSE_SCROLL_UP)
	{
		env->param.ref.x += ((-(env->width / 2) + x) * env->param.step * 0.1);
		env->param.ref.y += ((-(env->height / 2) + y) * env->param.step * 0.1);
		env->param.step /= 1.1;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		env->param.ref.x += ((-(env->width / 2) + x) * env->param.step * 0.1);
		env->param.ref.y += ((-(env->height / 2) + y) * env->param.step * 0.1);
		env->param.step *= 1.1;
	}
	else
		return (ft_printf("%#X\n", button));
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
	draw_fract_ol(env, &purlple_palet);
	mlx_put_image_to_window(env->mlx, env->window, env->img.img, 0, 0);
	mlx_destroy_image(env->mlx, env->img.img);
	return (1);
}
