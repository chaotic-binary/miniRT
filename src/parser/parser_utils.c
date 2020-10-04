/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:49:53 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:43:19 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parser.h"
#include "../../Includes/exit.h"

void	parse_color(char *arg, t_argb *color, char **args, int line_num)
{
	char	**val;
	int		i;

	val = ft_split(arg, ',');
	if (!val)
		parser_exit(args, ERRNO);
	if (arg_num(val) != 3)
		parse_vec_exit(args, val, ERR_COL, line_num);
	i = -1;
	while (val[++i])
	{
		if (!is_uint(val[i]))
			parse_vec_exit(args, val, ERR_COL, line_num);
	}
	*color = color_new(0, (float)ft_atoi(val[0]) / 255.0f, \
			(float)ft_atoi(val[1]) / 255.0f, (float)ft_atoi(val[2]) / 255.0f);
	if ((*color).r > 1.0 || (*color).g > 1.0 || (*color).b > 1.0)
	{
		write(1, "Error\nColors should be in range [0,255]\n", 40);
		parse_vec_exit(args, val, ERR_COL, line_num);
	}
	free_arr(val);
}

void	parse_coordinates(char *arg, t_vec3 *point, char **args, int line_num)
{
	char	**val;
	int		i;

	val = ft_split(arg, ',');
	if (!val)
		parser_exit(args, ERRNO);
	if (arg_num(val) != 3)
		parse_vec_exit(args, val, ERR_COORD, line_num);
	i = -1;
	while (val[++i])
	{
		if (!is_float(val[i], 1))
			parse_vec_exit(args, val, ERR_COORD, line_num);
	}
	*point = v_new(ft_atof(val[0]), ft_atof(val[1]), ft_atof(val[2]));
	free_arr(val);
}
