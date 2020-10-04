/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals_cy_co.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:26:04 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/29 19:08:15 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

t_vec3	n_cylinder(t_cy *cy)
{
	t_vec3	center_point;
	float	t1;
	t_ray	ray1;
	t_pl	pl;
	t_vec3	n;

	if (cy->t[3] > 0)
		n = cy->n;
	else if (cy->t[2] > 0)
		n = v_inv(cy->n);
	else
	{
		pl.o = cy->t_point;
		pl.n = cy->n;
		ray1.o = cy->p_top;
		ray1.n = cy->n;
		if (!(t1 = intersect_plane(ray1, &pl)))
			return (v_new(0, 0, 0));
		center_point = p_trans(ray1.o, ray1.n, t1);
		n = normal(center_point, cy->t_point);
	}
	return (n);
}

t_vec3	n_cone(t_cy *co)
{
	float	k;
	float	t1;
	t_ray	ray1;
	t_pl	pl;
	t_vec3	center_point;

	pl.o = co->t_point;
	pl.n = co->n;
	ray1.o = co->o;
	ray1.n = co->n;
	if (!(t1 = intersect_plane(ray1, &pl)))
		return (v_new(0, 0, 0));
	k = co->r / co->h;
	center_point = p_trans(co->o, co->n, t1 * (1 + k * k));
	return (normal(center_point, co->t_point));
}
