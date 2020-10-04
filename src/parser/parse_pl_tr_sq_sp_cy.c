/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pl_tr_sq_sp_cy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:54:36 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/03 23:28:20 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parser.h"
#include "../../Includes/render.h"
#include "../../Includes/exit.h"

void	parse_plane(char **args, t_scene *scene, int line_num)
{
	t_pl *pl;

	if (arg_num(args) != 4)
		parser_exit(args, line_num);
	if (!(pl = (t_pl *)malloc_c(sizeof(t_pl))))
		parser_exit(args, ERRNO);
	parse_coordinates(args[1], &pl->o, args, line_num);
	parse_coordinates(args[2], &pl->n, args, line_num);
	parse_color(args[3], &pl->color, args, line_num);
	if (!check_norm(&pl->n))
		parser_exit(args, line_num);
	pl->intersect = &intersect_plane;
	pl->normal = &n_plane;
	ft_lstadd_front(&scene->objs, ft_lstnew_c(pl));
}

void	parse_sphere(char **args, t_scene *scene, int line_num)
{
	t_sp *sp;

	if (arg_num(args) != 4 || !is_float(args[2], 0))
		parser_exit(args, line_num);
	if (!(sp = (t_sp *)malloc_c(sizeof(t_sp))))
		parser_exit(args, ERRNO);
	parse_coordinates(args[1], &sp->o, args, line_num);
	sp->r = ft_atof(args[2]) / 2;
	if (sp->r == 0)
		parser_exit(args, ERR_ZERO_SIZE);
	parse_color(args[3], &sp->color, args, line_num);
	sp->intersect = &intersect_sphere;
	sp->normal = &n_sphere;
	ft_lstadd_front(&scene->objs, ft_lstnew_c(sp));
}

void	parse_triangle(char **args, t_scene *scene, int line_num)
{
	t_tr *tr;

	if (arg_num(args) != 5)
		parser_exit(args, line_num);
	if (!(tr = (t_tr *)malloc_c(sizeof(t_tr))))
		parser_exit(args, ERRNO);
	parse_coordinates(args[1], &tr->v0, args, line_num);
	parse_coordinates(args[2], &tr->v1, args, line_num);
	parse_coordinates(args[3], &tr->v2, args, line_num);
	parse_color(args[4], &tr->color, args, line_num);
	tr->intersect = &intersect_triangle;
	tr->normal = &n_triangle;
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr));
}

void	parse_square(char **args, t_scene *scene, int line_num)
{
	t_sq *sq;

	if (arg_num(args) != 5 || !is_float(args[3], 0))
		parser_exit(args, line_num);
	if (!(sq = (t_sq *)malloc_c(sizeof(t_sq))))
		parser_exit(args, ERRNO);
	parse_coordinates(args[1], &sq->o, args, line_num);
	parse_coordinates(args[2], &sq->n, args, line_num);
	sq->h = ft_atof(args[3]);
	if (sq->h == 0)
		parser_exit(args, ERR_ZERO_SIZE);
	parse_color(args[4], &sq->color, args, line_num);
	if (!check_norm(&sq->n))
		parser_exit(args, line_num);
	sq->intersect = &intersect_square;
	sq->normal = &n_square;
	ft_lstadd_front(&scene->objs, ft_lstnew_c(sq));
}

void	parse_cylinder(char **args, t_scene *scene, int line_num)
{
	t_cy	*cy;
	int		n;

	n = arg_num(args);
	if (n < 6 || n > 7 || !is_float(args[3], 0) || !is_float(args[4], 0))
		parser_exit(args, line_num);
	if (n == 7 && ft_memcmp(args[6], "c", 2))
		parser_exit(args, line_num);
	if (!(cy = (t_cy *)malloc_c(sizeof(t_cy))))
		parser_exit(args, ERRNO);
	parse_coordinates(args[1], &cy->o, args, line_num);
	parse_coordinates(args[2], &cy->n, args, line_num);
	cy->r = ft_atof(args[3]) / 2;
	cy->h = ft_atof(args[4]);
	if (cy->r == 0 || cy->h == 0)
		parser_exit(args, ERR_ZERO_SIZE);
	parse_color(args[5], &cy->color, args, line_num);
	if (!check_norm(&cy->n))
		parser_exit(args, line_num);
	if (n == 6)
		cy->intersect = &intersect_cylinder;
	else
		cy->intersect = &intersect_cylinder_caps;
	cy->normal = &n_cylinder;
	ft_lstadd_front(&scene->objs, ft_lstnew_c(cy));
}
