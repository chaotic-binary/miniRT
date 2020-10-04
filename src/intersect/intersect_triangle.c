/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:08:35 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/20 23:31:37 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

float	intersect_triangle(t_ray ray, t_tr *tr)
{
	t_vec3	edge1;
	t_vec3	edge2;
	t_vec3	pvec;
	t_vec3	tvec;
	float	v[3];

	edge1 = v_minus(tr->v1, tr->v0);
	edge2 = v_minus(tr->v2, tr->v0);
	pvec = v_cross(ray.n, edge2);
	v[0] = v_dot(edge1, pvec);
	if (!v[0])
		return (0);
	v[0] = 1 / v[0];
	tvec = v_minus(ray.o, tr->v0);
	v[1] = v_dot(tvec, pvec) * v[0];
	if (v[1] < -ACC || v[1] > 1 + ACC)
		return (0);
	pvec = v_cross(tvec, edge1);
	v[2] = v_dot(ray.n, pvec) * v[0];
	if (v[2] < -ACC || v[1] + v[2] > 1 + ACC)
		return (0);
	return (v_dot(edge2, pvec) * v[0]);
}
