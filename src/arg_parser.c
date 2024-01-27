/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaladro <dbaladro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:49:46 by dbaladro          #+#    #+#             */
/*   Updated: 2024/01/27 22:21:20 by dbaladro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	free_argv(char ***str_tab_ptr)
{
	int	index;

	index = 0;
	while ((*str_tab_ptr)[index])
	{
		free(*(str_tab_ptr)[index]);
		*(str_tab_ptr)[index] = 0;
	}
	free(*str_tab_ptr);
	*str_tab_ptr = 0;
}

static char	**split_arg(int *av_len, char *av)
{
	char	**argv;

	*av_len = 0;
	argv = ft_split(av, ' ');
	if (!argv)
		return (NULL);
	while (argv[*av_len])
		*av_len += 1;
	if (*av_len == 0)
		return (free(argv), NULL);
	return (argv);
}

static int	add_arg(t_env *env, const char *arg, int pos)
{
	if (!arg)
		return (0);
	if (pos == 0)
	{
		set_fractal_function(env, arg);
		return (env->fractal != NULL);
	}
	if (pos == 1)
	{
		env->param.max_iter = ft_atoi(arg);
		return (10 <= env->param.max_iter && env->param.max_iter < 10000);
	}
	if (pos == 2)
	{
		if (env->fractal == &mandelbrot)
			return (0);
		env->fractal_arg = set_complex_param(arg);
		return (1);
	}
	return (0);
}

static void	add_arg_to_env(t_env *env, char **arg, int *arg_len)
{
	int	index;

	index = 0;
	while (arg[index])
	{
		if (!add_arg(env, arg[index], index))
		{
			*arg_len = -1;
			return ;
		}
		index++;
	}
	*arg_len = index;
}

/*
	Check If arg_is_valid
	Init t_env ?
	print help_msg if needed
	return t_env ?
*/
void	parse_arg(t_env *env, int ac, char **av)
{
	char	**arg;
	int		size;

	env->fractal = NULL;
	if (ac <= 1 || ac > 4)
		return ((void)ft_printf(FRACTOL_OPT));
	if (ac == 2)
	{
		arg = split_arg(&size, av[1]);
		if (!arg)
			return ;
		add_arg_to_env(env, arg, &size);
		free_argv(&arg);
	}
	else
		add_arg_to_env(env, av + 1, &size);
	if (size == -1)
	{
		ft_printf(FRACTOL_OPT);
		free(env);
		exit(0);
	}
}
