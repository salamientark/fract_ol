/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:08:43 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 09:00:22 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	main(void)
{
	t_env	*env;

	env = init_env(50, &mandelbrot);
	if (!env)
		return (0);
	mlx_loop_hook(env->mlx, &render, env);
	mlx_key_hook(env->window, &handle_key_hook, env);
	mlx_loop(env->mlx);
	free(env->mlx);
	free(env);
	return (0);
}
