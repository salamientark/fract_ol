/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:01:11 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 09:58:04 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

t_complex   c_add(t_complex c1, t_complex c2)
{
    t_complex   c_final;

    c_final.reel = c1.reel + c2.reel;
    c_final.img = c1.img + c2.img;
    return (c_final);
}

t_complex   c_pow2(t_complex c)
{
    t_complex   c_pow;

    c_pow.reel = c.reel * c.reel - (c.img * c.img);
    c_pow.img = 2 * c.reel * c.img;
    return (c_pow);
}

t_complex   pos_to_complex(t_pos pos)
{
    t_complex   c;
    double      middle_line;
    double      middle_col;

    middle_line = 540;
    middle_col = 960;
    c.reel = ((double)pos.pos_y - pos.offset_y - middle_col) / middle_line;// * (pos.zoom + 1);
    c.img = ((double)pos.pos_x - pos.offset_x - middle_line) / middle_line;// * (pos.zoom + 1);
    return (c);
}
