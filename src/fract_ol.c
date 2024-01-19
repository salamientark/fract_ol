/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:09:26 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 09:56:39 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double  modul_sum(t_complex c)
{
    return (c.reel * c.reel + c.img * c.img);
}

int mandelbrot(t_pos position, int max_iter)
{
    t_complex   z;
    t_complex   c;
    int         iter;

    z.reel = 0;
    z.img = 0;
    c = pos_to_complex(position);
    iter = 0;
    while (modul_sum(z) < 4 && iter < max_iter)
    {
        z = c_add(c_pow2(z), c);
        iter++;
    }
    return (iter);
}

void    draw_fract_ol(t_image *data, t_env env,
    int (*fract_ol)(t_pos, int), int (*color)(double, double))
{
    t_pos  pos;
    int    iter;
    (void) color;

    pos.pos_x = 0;
    pos.offset_x = env.pos.offset_x;
    pos.offset_y = env.pos.offset_y;
    pos.zoom = env.pos.zoom;
    while (pos.pos_x < 1080)
    {
        pos.pos_y = 0;
        while (pos.pos_y < 1920)
        {
            iter = fract_ol(pos, env.max_iter);
            if (iter == env.max_iter)
                my_mlx_pixel_put(data, pos.pos_x, pos.pos_y, 0x00000000);
            else
                my_mlx_pixel_put(data, pos.pos_x, pos.pos_y,
                    color(iter, env.max_iter));
            pos.pos_y++;
        }
        pos.pos_x++;
    }
    ft_printf("End_fractal\n");
}
