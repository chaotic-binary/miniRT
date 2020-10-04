/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:53:10 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/02 23:25:36 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

static t_argb	light_color(t_vec3 ray_n, t_l *l, t_vec3 obj_n)
{
	t_argb	color;
	float	l_rat;
	t_vec3	v;
	t_vec3	r;

	normal_correct(&obj_n, ray_n);
	v = v_inv(ray_n);
	color = color_new(0, 0, 0, 0);
	r = v_normalize(v_minus(v_multn(obj_n, 2.0 * v_dot(obj_n, l->n)), l->n));
	l_rat = l->ratio * fmaxf(v_dot(obj_n, l->n), 0);
	if (SHINE)
		l_rat += l->ratio * pow(fmaxf(v_dot(r, v), 0), SHINE);
	if (l_rat > 1)
		l_rat = 1;
	if (l_rat > 0)
		color = color_multn(l->color, l_rat);
	return (color);
}

static float	parallel_light_t(t_l *l, t_vec3 p)
{
	t_ray	l_ray;
	float	t;
	t_pl	pl;

	if (v_dot(normal(p, l->o), l->n) < 0)
		return (-1);
	l_ray.n = l->n;
	l_ray.o = p;
	pl.o = l->o;
	pl.n = l_ray.n;
	t = intersect_plane(l_ray, &pl);
	l->o = p_trans(p, l->n, t);
	return (t);
}

static int		in_shadow(t_list *objs, t_l *l, t_vec3 t_point)
{
	float t_closest;
	float t_current;
	float dist;
	t_obj *obj_current;

	if (l->type && parallel_light_t(l, t_point) < ACC)
		return (1);
	l->n = v_inv(l->n);
	dist = v_dist(l->o, t_point);
	t_closest = INFINITY;
	while (objs)
	{
		obj_current = objs->content;
		t_current = obj_current->intersect(*((t_ray *)l), obj_current);
		if (t_current > ACC && t_current < t_closest)
			t_closest = t_current;
		objs = objs->next;
	}
	l->n = v_inv(l->n);
	if (dist <= t_closest + 0.1 && dist > t_closest - 0.1)
		return (0);
	return (1);
}

static t_argb	local_color(t_ray ray, t_scene *scene, t_obj *obj)
{
	t_argb ambient;
	t_argb res;
	t_list *lights;
	t_vec3 obj_n;

	lights = scene->lights;
	ambient = color_multn(scene->ambient.color, scene->ambient.ratio);
	res = color_new(0, 0, 0, 0);
	obj_n = obj->normal(obj);
	while (lights)
	{
		if (((t_l *)lights->content)->type == 0)
			((t_l *)lights->content)->n = normal(obj->t_point, \
											((t_l *)lights->content)->o);
		if ((v_dot(obj_n, ray.n) > 0) != \
			(v_dot(obj_n, ((t_l *)lights->content)->n) > 0) \
			&& (!in_shadow(scene->objs, (t_l *)lights->content, obj->t_point)))
			res = color_plus(res, light_color(ray.n, \
										(t_l *)lights->content, obj_n));
		lights = lights->next;
	}
	res = color_mult(color_plus(ambient, res), obj->color);
	return (res);
}

unsigned		trace_ray(t_scene *scene, t_list *objs, t_ray ray, int filter)
{
	float t_closest;
	float t_current;
	t_obj *obj_current;
	t_obj *obj_closest;

	t_closest = INFINITY;
	while (objs)
	{
		obj_current = objs->content;
		t_current = obj_current->intersect(ray, obj_current);
		if (t_current > ACC && t_current + ACC < t_closest)
		{
			t_closest = t_current;
			obj_closest = obj_current;
		}
		objs = objs->next;
	}
	if (t_closest == INFINITY)
		return (0);
	obj_closest->t_point = p_trans(ray.o, ray.n, t_closest);
	if (filter & 1)
		return (int_color(filter_sepia(local_color(ray, scene, obj_closest))));
	return (int_color(local_color(ray, scene, obj_closest)));
}
