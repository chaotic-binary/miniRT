/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_datacheck.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:47:43 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/08 16:51:33 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parser.h"
#include "../../Includes/exit.h"

int	arg_num(char **args)
{
	int i;

	i = 0;
	while (args[i])
		++i;
	return (i);
}

int	is_int(char *w)
{
	int i;

	i = -1;
	if (w[0] == '+' || w[0] == '-')
		++i;
	while (w[++i])
	{
		if (!ft_isdigit(w[i]))
			return (0);
	}
	return (1);
}

int	is_float(char *w, int neg)
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	if (w[0] == '-' && !neg)
	{
		write(1, "Error\nNegative obj size or light ratio\n", 39);
		return (0);
	}
	if ((neg && w[i] == '-') || w[i] == '+')
		++i;
	while (w[i] && ft_isdigit(w[i]))
		++i;
	if (w[i] == '.')
	{
		++i;
		while (w[i] && ft_isdigit(w[i]))
			++i;
	}
	if (!w[i] || (w[i] == 'f' && !w[i + 1]))
		return (1);
	return (0);
}

int	check_float_range(float n, float min, float max)
{
	if (n >= min && n <= max)
		return (1);
	return (0);
}

int	check_norm(t_vec3 *v)
{
	if (v_dist(*v, v_new(0, 0, 0)) == 0)
	{
		write(1, "Error\nThe length of normalized ort vector is 0\n", 47);
		return (0);
	}
	if (v_dist(*v, v_new(0, 0, 0)) != 1)
		*v = v_normalize(*v);
	return (1);
}

/*
** strict version
** 	if (v_dist(*v, v_new(0, 0, 0)) > 1)
** 	{
** 		write(1, "Error\nThe length of normalized ort vector is > 1\n", 49);
** 		return (0);
** 	}
** 	if (v_dist(*v, v_new(0, 0, 0)) < 1)
** 	{
** 		write(1, "Error\nThe length of normalized ort vector is < 1\n", 49);
** 		return (0);
** 	}
*/
