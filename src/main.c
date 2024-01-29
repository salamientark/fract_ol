/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:08:43 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/29 07:57:52 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	main(int ac, char **av)
{
	t_env	*env;

	env = init_fract_ol(ac, av);
	if (!env)
		return (0);
	mlx_loop_hook(env->mlx, &render, env);
	mlx_key_hook(env->window, &handle_key_hook, env);
	mlx_mouse_hook(env->window, &handle_mouse_hook, env);
	mlx_hook(env->window, 17, 0, &exit_fractol, env);
	mlx_loop(env->mlx);
	free(env->mlx);
	free(env);
	return (0);
}
