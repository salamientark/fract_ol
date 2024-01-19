/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:01:59 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 09:45:16 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../miniLibX/mlx.h"
# include "../libft/includes/libft.h"
# include "ft_math.h"

#ifndef M_PI
# define M_PI 3.141592653589793
#endif

/*
    Datato write to image:
    img:
    addr: img starting addr ?
    bits_per_pixel:?
    line_length: ?
    endian: ?
*/
typedef struct	s_image
 {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

/*
    Position (REAL POSITIVE NUMBERS)
*/
typedef struct s_pos
{
    int pos_x;
    int pos_y;
    double offset_x;
    double offset_y;
    double zoom;
}               t_pos;

typedef struct s_env
{
    int     max_iter;
    t_pos   pos;
}           t_env;

/*   __  __ _   __  __
    |  \/  | |  \ \/ /
    | |\/| | |__ >  < 
    |_|  |_|____/_/\_\
*/
void            my_mlx_pixel_put(t_image *data, int x, int y, int color);

/*    ___ ___  _    ___  ___  ___ 
     / __/ _ \| |  / _ \| _ \/ __|
    | (_| (_) | |_| (_) |   /\__ \
     \___\___/|____\___/|_|_\|___/                           
*/
int             make_color(int t, int r, int g, int b);
int             purlple_palet(double iter, double max_iter);

/*   ___ _____    __  __   _ _____ _  _ 
    | __|_   _|__|  \/  | /_\_   _| || |
    | _|  | ||___| |\/| |/ _ \| | | __ |
    |_|   |_|    |_|  |_/_/ \_\_| |_||_|
*/
// math.c
unsigned int    ft_abs(int n);
int             rescale(int old_min, int old_max, int new_min, int new_max,
                    double value);

// complex.c
t_complex       c_add(t_complex c1, t_complex c2);
t_complex       c_pow2(t_complex c);
t_complex       pos_to_complex(t_pos pos);

/*   ___ ___    _   ___ _____     ___  _    
    | __| _ \  /_\ / __|_   _|__ / _ \| |   
    | _||   / / _ \ (__  | ||___| (_) | |__ 
    |_| |_|_\/_/ \_\___| |_|     \___/|____|
*/
int             mandelbrot(t_pos position, int max_iter);
void            draw_fract_ol(t_image *data, t_env env,
    int (*fract_ol)(t_pos, int), int (*color)(double, double));

#endif