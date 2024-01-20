/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_setter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:13:24 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/20 22:52:16 by madlab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	free_split(char ***split_ptr)
{
	char	**split_cp;
	int		index;

	index = 0;
	split_cp = *split_ptr;
	while (split_cp[index])
	{
		free(split_cp[index]);
		split_cp[index] = NULL;
		index++;
	}
	free(*split_ptr);
	*split_ptr = NULL;
}

/*
	get_function based on input
*/
void	set_fractal_function(t_env *env, const char *s)
{
	if ((ft_strlen(s) == 1 && s[0] == 'M') || ft_strcmp(s, "Mandelbrot") == 0)
	{
		env->fractal = &mandelbrot;
		env->param.ref.x = env->width / 2;
		env->param.ref.y = env->height / 2;
	}
	else if ((ft_strlen(s) == 1 && s[0] == 'J') || ft_strcmp(s, "Julia") == 0)
		env->fractal = &julia;
	else
		env->fractal = NULL;
}

/*
	Check_complete param
*/
static int	is_double_valid(const char *s)
{
	while (*s && (('\t' <= *s && *s <= '\r') || *s == ' '))
		s++;
	if (!(*s))
		return (0);
	while (*s && (*s == '-' || *s == '+'))
		s++;
	if (!(*s))
		return (0);
	while (*s && (ft_isdigit(*s)))
		s++;
	if (!(*s))
		return (ft_isdigit(*(s - 1)));
	if (!(*s == '.'))
		return (0);
	s++;
	while (*s && (ft_isdigit(*s)))
		s++;
	return (!(*s) && ft_isdigit(*(s - 1)));
}

/*
	Get complex param
*/
t_complex	set_complex_param(const char *s)
{
	char		**nbr;
	t_complex	c;

	c.reel = 0;
	c.img = 0;
	nbr = ft_split(s, ',');
	if (!nbr)
		return (c);
	if (!nbr[0] || !is_double_valid(nbr[0])
		|| (nbr[1] && !is_double_valid(nbr[1])) || nbr[2])
		return (free_split(&nbr), c);
	c.reel = ft_str_to_double(nbr[0]);
	if (nbr[1])
		c.img = ft_str_to_double(nbr[1]);
	free_split(&nbr);
	return (c);
}
