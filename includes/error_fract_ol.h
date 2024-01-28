/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fract_ol.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:14:11 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/28 09:31:12 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_FRACT_OL_H
# define ERROR_FRACT_OL_H

# include <string.h>

# define FRACTOL_OPT "usage: fract_ol [fractal] [max_iteration] [complex]\n\
 fractal:\n\
--> M Mandelbrot\n\
--> J Julia\n\
 max_iteration\n\
--> (int): [10, 100]\n\
 complex (only with julia)\n\
--> (double,double): [-1.0, -1.0]\n"

#endif