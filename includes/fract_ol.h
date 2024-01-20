/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:01:59 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/19 23:14:12 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../miniLibX/mlx.h"
# include "../libft/includes/libft.h"
# include "ft_keycode.h"
# include "ft_math.h"

#ifndef M_PI
# define M_PI 3.141592653589793
#endif

# define WINDOW_TITLE "Fract_ol"

/*
    Datato write to image:
    img:
    addr: img starting addr ?
    bits_per_pixel:?
    line_length: ?
    endian: ?
*/
typedef struct	s_img
 {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/*
    Position (REAL POSITIVE NUMBERS)
*/
typedef struct s_pos
{
    int x;
    int y;
}               t_pos;

/*
    screen_print parameter
*/
typedef struct s_param
{
    int     max_iter;
    double  zoom;
    t_pos   ref;
    t_pos   offset;
}               t_param;

/*
    mlx environment
*/
typedef struct s_env
{
    void    *mlx;
    void    *window;
    int     width;
    int     height;
    t_img   img;
    t_param param;
    int     (*fractal)(t_pos, struct s_env);
}           t_env;

/*   __  __ _   __  __
    |  \/  | |  \ \/ /
    | |\/| | |__ >  < 
    |_|  |_|____/_/\_\
*/
void            my_mlx_pixel_put(t_img *data, int x, int y, int color);

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
t_complex       pos_to_complex(t_pos pos, t_param param);

/*   ___ ___    _   ___ _____     ___  _    
    | __| _ \  /_\ / __|_   _|__ / _ \| |   
    | _||   / / _ \ (__  | ||___| (_) | |__ 
    |_| |_|_\/_/ \_\___| |_|     \___/|____|
*/
void            exit_fractol(t_env *env);
int             mandelbrot(t_pos position, t_env env);
void            draw_fract_ol(t_env *env, int (*color)(double, double));

/*
    HOOK
*/
int handle_key_hook(int keycode, void *param);

#endif