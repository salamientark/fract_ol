/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:09:26 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:31 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double  modul_sum(t_complex c)
{
    return (c.reel * c.reel + c.img * c.img);
}

int mandelbrot(t_pos position, t_env env)
{
    t_complex   z;
    t_complex   c;
    int         iter;
    int         max_iteration;

    z.reel = 0;
    z.img = 0;
    c = pos_to_complex(position, env.param);
    iter = 0;
    max_iteration = env.param.max_iter;
    while (modul_sum(z) < 4 && iter < max_iteration)
    {
        z = c_add(c_pow2(z), c);
        iter++;
    }
    return (iter);
}

void    draw_fract_ol(t_env env, int (*color)(double, double))
{
    t_pos  pos;
    int    iter;

    pos.x = 0;
    while (pos.x < env.height)
    {
        pos.y = 0;
        while (pos.y < env.width)
        {
            iter = env.fractal(pos, env);
            if (iter == env.param.max_iter)
                my_mlx_pixel_put(&(env.img), pos.x, pos.y, 0x00000000);
            else
                my_mlx_pixel_put(&(env.img), pos.x, pos.y,
                    color(iter, env.param.max_iter));
            pos.y++;
        }
        pos.x++;
    }
    ft_printf("End_fractal\n");
}
