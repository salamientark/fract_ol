/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 08:12:54 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/27 22:04:16 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
	Init fract_ol env variable
*/
t_env	*init_env(int ac, char **av)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(struct s_env));
	if (!env)
		return (NULL);
	env->param.max_iter = 50;
	parse_arg(env, ac, av);
	if (!(env->fractal))
		return (free(env), NULL);
	env->mlx = mlx_init();
	if (!(env->mlx))
		return (NULL);
	mlx_get_screen_size(env->mlx, &(env->width), &(env->height));
	env->window = mlx_new_window(env->mlx, env->width, env->height,
			WINDOW_TITLE);
	if (!(env->window))
		return ((void)mlx_destroy_display(env->mlx), free(env->mlx),
			free(env), NULL);
	env->param.step = 1. / (fmin(env->height, env->width) / 2.);
	env->param.ref.x = 0.;
	env->param.ref.y = 0.;
	env->param.zoom = 1;
	return (env);
}

/*
	Destroy window + display + free + exit
*/
void	exit_fractol(t_env *env)
{
	mlx_clear_window(env->mlx, env->window);
	mlx_destroy_window(env->mlx, env->window);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	free(env);
	exit(0);
}
