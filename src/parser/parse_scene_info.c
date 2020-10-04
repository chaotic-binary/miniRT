/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:54:28 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/03 23:27:46 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parser.h"
#include "../../Includes/render.h"
#include "../../Includes/exit.h"

void		parse_resolution(char **args, t_scene *scene, int line_num)
{
	if (scene->resolution[2])
		parser_exit(args, ERR_DOUBLE_R);
	scene->resolution[2] = 1;
	if (arg_num(args) != 3 || !is_uint(args[1]) || !is_uint(args[2]))
		parser_exit(args, line_num);
	scene->resolution[X] = ft_atoi(args[1]);
	scene->resolution[Y] = ft_atoi(args[2]);
	if (scene->resolution[X] <= 0 || scene->resolution[Y] <= 0)
	{
		write(1, "Error\nResolution should be positive\n", 36);
		parser_exit(args, line_num);
	}
}

void		parse_ambient(char **args, t_scene *scene, int line_num)
{
	if (scene->ambient.set)
		parser_exit(args, ERR_DOUBLE_A);
	scene->ambient.set = 1;
	if (arg_num(args) != 3 || !is_float(args[1], 0))
		parser_exit(args, line_num);
	scene->ambient.ratio = ft_atof(args[1]);
	parse_color(args[2], &scene->ambient.color, args, line_num);
	if (!check_float_range(scene->ambient.ratio, 0, 1))
	{
		write(1, "Error\nBrightness ratio should be in range [0.0,1.0]\n", 52);
		parser_exit(args, line_num);
	}
}

static void	process_filters(t_c *cam, char **args, int line_num)
{
	if (ft_memcmp(args[4], "sepia", 6) == 0)
		cam->filter = 1;
	else if (ft_memcmp(args[4], "aa", 3) == 0)
		cam->filter = 2;
	else if (ft_memcmp(args[4], "sepia+aa", 9) == 0)
		cam->filter = 3;
	else
		parser_exit(args, line_num);
}

void		parse_camera(char **args, t_scene *scene, int line_num)
{
	t_c	*cam;
	int	n;

	if ((n = arg_num(args)) < 4 || n > 5 || !is_uint(args[3]))
		parser_exit(args, line_num);
	if (!(cam = (t_c *)malloc_c(sizeof(t_c))))
		parser_exit(args, ERRNO);
	cam->filter = 0;
	if (n == 5)
		process_filters(cam, args, line_num);
	parse_coordinates(args[1], &cam->pos, args, line_num);
	parse_coordinates(args[2], &cam->n, args, line_num);
	cam->fov = ft_atoi(args[3]);
	if (cam->fov > 180 || cam->fov < 0)
	{
		write(1, "Error\nFOV should be in range [0, 180]\n", 38);
		parser_exit(args, line_num);
	}
	if (!check_norm(&cam->n))
		parser_exit(args, line_num);
	ft_dlstadd_back(&scene->cams, ft_dlstnew_c(cam));
}

void		parse_light(char **args, t_scene *scene, int line_num)
{
	t_l	*l;
	int	n;

	if ((n = arg_num(args)) < 4 || n > 5 || !is_float(args[2], 0))
		parser_exit(args, line_num);
	if (!(l = (t_l *)malloc_c(sizeof(t_l))))
		parser_exit(args, ERRNO);
	l->type = 0;
	if (n == 5)
	{
		l->type = 1;
		parse_coordinates(args[4], &l->n, args, line_num);
		l->n = v_inv(l->n);
		if (!check_norm(&l->n))
			parser_exit(args, line_num);
	}
	parse_coordinates(args[1], &l->o, args, line_num);
	l->ratio = ft_atof(args[2]);
	parse_color(args[3], &l->color, args, line_num);
	if (!check_float_range(l->ratio, 0, 1))
	{
		write(1, "Error\nBrightness ratio should be in range [0.0,1.0]\n", 52);
		parser_exit(args, line_num);
	}
	ft_lstadd_front(&scene->lights, ft_lstnew_c(l));
}
