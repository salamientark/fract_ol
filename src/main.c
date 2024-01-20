/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:08:43 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 08:02:33 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include <stdio.h>

// t_img	draw_image(t_env *env)
// {
// 	image.img = mlx_new_image(env->mlx, env->width, env->height);
// 	if (!(image.img))
// 		exit_fractol(env);
// 	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
// 		&image.line_length, &image.endian);
// 	if (!(image.addr))
// 	{
// 		(void)mlx_destroy_image(env->mlx, env->img.img);
// 		exit_fractol(env);
// 	}
// 	draw_fract_ol(env, &purlple_palet);
// 	mlx_put_image_to_window(env->mlx, env->window, env->img.img, 0, 0);
// }

t_env	*init_env(int max_iter, int (*fractal)(t_pos, t_env))
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(struct s_env));
	if (!env)
		return (NULL);
	env->mlx = mlx_init();
	if (!(env->mlx))
		return (NULL);
	mlx_get_screen_size(env->mlx, &(env->width), &(env->height));
	env->window = mlx_new_window(env->mlx, env->width, env->height,
		WINDOW_TITLE);
	if (!(env->window))
		return ((void)mlx_destroy_display(env->mlx), free(env->mlx),
			free(env), NULL);
	env->param.max_iter = max_iter;
	env->param.ref.x = env->width - (fmin(env->width, env->height) / 2);
	env->param.ref.y = env->height - (fmin(env->width, env->height) / 2);
	env->param.offset.x = 0;
	env->param.offset.y = 0;
	env->param.zoom = 0;
	env->fractal = fractal;
	return (env);
}

int	render(t_env *env)
{
	// mlx_clear_window(env->mlx, env->img.img);
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

int main()
{
	t_env	*env;

	env = init_env(50, &mandelbrot);
	if (!env)
		return (0);
	mlx_loop_hook(env->mlx, &render, env);
	mlx_key_hook(env->window, &handle_key_hook, env);
	mlx_loop(env->mlx);
	// mlx_destroy_display(env->mlx);
	// free(env->mlx);
	// free(env);
	// mlx_destroy_display(env->mlx);
	free(env->mlx);
	free(env);
    return (0);
}
