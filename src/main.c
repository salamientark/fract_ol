/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:08:43 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:47 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include <stdio.h>

t_img	init_image(t_env env)
{
	t_img image;

	image.img = mlx_new_image(env.mlx, env.width, env.height);
	if (!(image.img))
		return (image);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
		&image.line_length, &image.endian);
	if (!(image.addr))
		return ((void)mlx_destroy_image(env.mlx, env.img.img), image);
	return (image);
}

t_env	init_env(int max_iter, int (*fractal)(t_pos, t_env))
{
	t_env	env;

	env.fractal = NULL;
	env.mlx = mlx_init();
	if (!(env.mlx))
		return (env);
	mlx_get_screen_size(env.mlx, &(env.width), &(env.height));
	env.window = mlx_new_window(env.mlx, env.width, env.height, WINDOW_TITLE);
	if (!(env.window))
		return ((void)mlx_destroy_display(env.mlx), env);
	env.img = init_image(env);
	if (!(env.img.img) || !(env.img.addr))
		return ((void)mlx_destroy_window(env.mlx, env.window),
			(void)mlx_destroy_display(env.mlx), env);
	env.param.max_iter = max_iter;
	env.param.ref.x = env.width - (fmin(env.width, env.height) / 2);
	env.param.ref.y = env.height - (fmin(env.width, env.height) / 2);
	env.param.offset.x = 0;
	env.param.offset.y = 0;
	env.param.zoom = 0;
	env.fractal = fractal;
	return (env);
}

int	render(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->window, env->img.img, 0, 0);
	return (1);
}

int main()
{
	t_env	env;

	env = init_env(50, &mandelbrot);
	if (!env.fractal)
		return (0);
    draw_fract_ol(env, &purlple_palet);
	mlx_put_image_to_window(env.mlx, env.window, env.img.img, 0, 0);
	
	mlx_loop_hook(env.mlx, &render, &env);
	mlx_key_hook(env.window, &handle_key_hook, &env);
	mlx_loop(env.mlx);
    return (0);
}
