/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:08:43 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 22:56:55 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_env	*env;

	env = init_env(ac, av);
	if (!env)
		return (0);
	mlx_loop_hook(env->mlx, &render, env);
	mlx_key_hook(env->window, &handle_key_hook, env);
	mlx_mouse_hook(env->window, &handle_mouse_hook, env);
	mlx_loop(env->mlx);
	free(env->mlx);
	free(env);
	return (0);
}
