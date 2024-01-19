/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:49:27 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 16:00:25 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int handle_key_hook(int keycode, void *param)
{
    t_env *param_cp;

    param_cp = (t_env *)param;
    if (keycode == ARROW_RIGHT)
        param_cp->param.offset.y += 10;
    else if (keycode == ARROW_LEFT)
        param_cp->param.offset.y -= 10;
    else if (keycode == ARROW_UP)
        param_cp->param.offset.x += 10;
    else if (keycode == ARROW_DOWN)
        param_cp->param.offset.x -= 10;
    else if (keycode == ESC)
        exit(0);
    else
        return (ft_printf("%d\n", keycode));
    return (0);
}