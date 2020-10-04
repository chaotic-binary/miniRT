/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cu_py_co.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 21:02:06 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/01 04:33:14 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parser.h"
#include "../../Includes/render.h"
#include "../../Includes/exit.h"

static void	fill_sq_verteces(t_vec3 sq_c, t_vec3 n, float h_half, t_vec3 *v)
{
	t_vec3	axis;
	t_vec3	ox;
	t_vec3	oy;

	axis = (fabs(n.y) == 1) ? v_new(0, 0, 1) : v_new(0, 1, 0);
	ox = v_normalize(v_cross(n, axis));
	oy = v_normalize(v_cross(n, ox));
	ox = v_multn(ox, h_half);
	oy = v_multn(oy, h_half);
	v[0] = v_plus(v_plus(ox, oy), sq_c);
	v[1] = v_plus(v_plus(v_inv(ox), oy), sq_c);
	v[2] = v_plus(v_plus(v_inv(ox), v_inv(oy)), sq_c);
	v[3] = v_plus(v_plus(ox, v_inv(oy)), sq_c);
}

static t_tr	*tr(t_argb color, t_vec3 v0, t_vec3 v1, t_vec3 v2)
{
	t_tr	*tr;

	if (!(tr = (t_tr *)malloc_c(sizeof(t_tr))))
		free_and_exit(ERRNO);
	tr->intersect = &intersect_triangle;
	tr->normal = &n_triangle;
	tr->v0 = v0;
	tr->v1 = v1;
	tr->v2 = v2;
	tr->color = color;
	return (tr);
}

void		parse_pyramid(char **args, t_scene *scene, int line_num)
{
	t_vec3	v[4];
	t_cy	py;
	t_vec3	sq_c;

	if (arg_num(args) != 6 || !is_float(args[3], 0) || !is_float(args[4], 0))
		parser_exit(args, line_num);
	parse_coordinates(args[1], &py.o, args, line_num);
	parse_coordinates(args[2], &py.n, args, line_num);
	py.h = ft_atof(args[4]);
	py.r = ft_atof(args[3]) / 2;
	if (py.r == 0 || py.h == 0)
		parser_exit(args, ERR_ZERO_SIZE);
	parse_color(args[5], &py.color, args, line_num);
	if (!check_norm(&py.n))
		parser_exit(args, line_num);
	sq_c = p_trans(py.o, v_inv(py.n), py.h);
	fill_sq_verteces(sq_c, py.n, py.r, v);
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(py.color, v[3], v[1], v[2])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(py.color, v[0], v[1], v[3])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(py.color, v[0], v[1], py.o)));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(py.color, v[2], v[1], py.o)));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(py.color, v[2], v[3], py.o)));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(py.color, v[0], v[3], py.o)));
}

void		parse_cube(char **args, t_scene *scene, int line_num)
{
	float	h_half;
	t_sq	sq1;
	t_vec3	v[4];
	t_vec3	u[4];

	parse_square(args, scene, line_num);
	h_half = ((t_sq *)(scene->objs->content))->h / 2;
	sq1 = *((t_sq *)(scene->objs->content));
	((t_sq *)(scene->objs->content))->o = p_trans(sq1.o, sq1.n, h_half);
	fill_sq_verteces(((t_sq *)(scene->objs->content))->o, sq1.n, h_half, v);
	sq1.n = v_inv(sq1.n);
	u[0] = p_trans(v[0], sq1.n, sq1.h);
	u[1] = p_trans(v[1], sq1.n, sq1.h);
	u[2] = p_trans(v[2], sq1.n, sq1.h);
	u[3] = p_trans(v[3], sq1.n, sq1.h);
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, u[3], u[1], u[2])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, u[0], u[1], u[3])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, v[0], v[1], u[0])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, u[0], v[1], u[1])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, v[3], v[2], u[3])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, u[3], v[2], u[2])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, v[1], v[2], u[1])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, u[1], v[2], u[2])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, v[0], v[3], u[0])));
	ft_lstadd_front(&scene->objs, ft_lstnew_c(tr(sq1.color, v[3], u[3], u[0])));
}

void		parse_cone(char **args, t_scene *scene, int line_num)
{
	parse_cylinder(args, scene, line_num);
	((t_cy *)(scene->objs->content))->intersect = &intersect_cone;
	((t_cy *)(scene->objs->content))->normal = &n_cone;
}
