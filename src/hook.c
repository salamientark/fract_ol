/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 08:03:59 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void    free_mlx(t_env env)
{
    mlx_destroy_image(env.mlx, env.img.img);
    // free(env.img.img);
    mlx_destroy_window(env.mlx, env.window);
    // free(env.window);
    mlx_destroy_display(env.mlx);
    free(env.mlx);
}

void    exit_fractol(t_env *env)
{
    // mlx_destroy_image(env->mlx, env->img.img);
    mlx_clear_window(env->mlx, env->window);
    mlx_destroy_window(env->mlx, env->window);
    mlx_destroy_display(env->mlx);
    free(env->mlx);
    free(env);
    exit(0);
}

int handle_key_hook(int keycode, void *param)
{
    t_env *env_cp;

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
    // env_cp->img.img = mlx_new_image(env_cp->mlx, env_cp->width, env_cp->height);
    return (0);
}