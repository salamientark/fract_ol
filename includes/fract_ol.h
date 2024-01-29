/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:01:59 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/29 07:58:56 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../miniLibX/mlx.h"
# include "../libft/includes/libft.h"
# include "ft_keycode.h"
# include "error_fract_ol.h"
# include <math.h>

# ifndef M_PI
#  define M_PI 3.141592653589793
# endif

# define WINDOW_TITLE "Fract_ol"
# define MAX_ITER_DOWN_LIMIT 10.
# define MAX_ITER_UP_LIMIT 255.

/*
	Complex numbers
*/
typedef struct s_complex
{
	double	reel;
	double	img;
}				t_complex;

/*
	Data to write to image:
	img:
	addr: img starting addr ?
	bits_per_pixel:?
	line_length: ?
	endian: ?
*/
typedef struct s_img
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
typedef struct s_t_pos
{
	double	x;
	double	y;
}				t_pos;

/*
	screen_print parameter
*/
typedef struct s_param
{
	double	max_iter;
	double	step;
	t_pos	ref;
}				t_param;

/*
	mlx environment
*/
typedef struct s_env
{
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	t_img		img;
	t_param		param;
	void		(*fractal)(struct s_env *, int (*color)(double, double));
	t_complex	fractal_arg;
	int			(*color)(double, double);
	int			hud;
}				t_env;

/*   __  __ _   __  __
	|  \/  | |  \ \/ /
	| |\/| | |__ >  < 
	|_|  |_|____/_/\_\
*/
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

/*	  ___ ___  _	___  ___  ___ 
	 / __/ _ \| |  / _ \| _ \/ __|
	| (_| (_) | |_| (_) |   /\__ \
	 \___\___/|____\___/|_|_\|___/ 
*/
int				purlple_palet(double iter, double max_iter);
int				multicolor_palet(double iter, double max_iter);
int				zoom_color(double iter, double max_iter);

/*   ___ _____    __  __   _ _____ _  _ 
	| __|_   _|__|  \/  | /_\_   _| || |
	| _|  | ||___| |\/| |/ _ \| | | __ |
	|_|   |_|    |_|  |_/_/ \_\_| |_||_|
*/
// math.c
double			ft_abs(double n);
double			ft_str_to_double(char *str);
t_complex		init_complex(double reel, double imaginary);

/*   ___ ___	_   ___ _____	 ___  _	
	| __| _ \  /_\ / __|_   _|__ / _ \| |   
	| _||   / / _ \ (__  | ||___| (_) | |__ 
	|_| |_|_\/_/ \_\___| |_|	 \___/|____|
*/
// === ARG_GETTER ===
void			set_fractal_function(t_env *env, const char *s);
t_complex		set_complex_param(const char *s);

// === ARG_PARSER ===
void			parse_arg(t_env *env, int ac, char **av);

// fractol_env.c
t_env			*init_fract_ol(int ac, char **av);
int				exit_fractol(t_env *env);

// fract_ol.c
void			julia(t_env *env, int (*color)(double, double));
void			mandelbrot(t_env *env, int (*color)(double, double));
void			burning_ship(t_env *env, int (*color)(double, double));

/*   _  _  ___   ___  _  __
	| || |/ _ \ / _ \| |/ /
	| __ | (_) | (_) | ' < 
	|_||_|\___/ \___/|_|\_\
*/
int				render(t_env *env);
int				handle_key_hook(int keycode, void *param);
int				handle_mouse_hook(int button, int x, int y, void *param);

#endif
