/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 08:59:47 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
	Hook when key release
*/
int	handle_key_hook(int keycode, void *param)
{
	t_env	*env_cp;

	env_cp = (t_env *)param;
	if (keycode == ARROW_RIGHT)
		env_cp->param.offset.y -= 10;
	else if (keycode == ARROW_LEFT)
		env_cp->param.offset.y += 10;
	else if (keycode == ARROW_UP)
		env_cp->param.offset.x += 10;
	else if (keycode == ARROW_DOWN)
		env_cp->param.offset.x -= 10;
	else if (keycode == ESC)
		exit_fractol(env_cp);
	else
		return (ft_printf("%d\n", keycode));
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
