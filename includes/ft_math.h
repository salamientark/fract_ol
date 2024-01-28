/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:08:17 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/28 09:40:01 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <math.h>

/*
	Complex numbers
*/
typedef struct s_complex
{
	double	reel;
	double	img;
}				t_complex;

double			ft_abs(double n);
t_complex		c_add(t_complex c1, t_complex c2);
t_complex		c_pow2(t_complex c);

#endif
