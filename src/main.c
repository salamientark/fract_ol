/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:08:43 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 09:58:20 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"
#include <stdio.h>

int main()
{
    void	*mlx;
	void	*mlx_win;
	t_env	env;
	t_image	img;

    

	mlx = mlx_init();
    // if (mlx == (void *)0)
        // return (0);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	env.max_iter = 65;
	env.pos.pos_x = 0;
	env.pos.pos_y = 0;
	env.pos.offset_x = 0;
	env.pos.offset_y = 400;
	env.pos.zoom = 0;
    draw_fract_ol(&img, env, &mandelbrot, &purlple_palet);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
    return (0);
}
