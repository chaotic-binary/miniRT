/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_no_caps.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:03:30 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/03 17:20:28 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

static int		intersect_side(float *t, t_ray ray, t_cy *cy)
{
	t_vec3		x;
	float		coef[3];

	cy->n = normal(cy->p_top, cy->o);
	x = v_minus(ray.o, cy->p_top);
	coef[0] = v_dot(ray.n, ray.n) - pow(v_dot(ray.n, cy->n), 2);
	coef[1] = 2 * (v_dot(ray.n, x) - \
									v_dot(ray.n, cy->n) * v_dot(x, cy->n));
	coef[2] = v_dot(x, x) - pow(v_dot(x, cy->n), 2) - cy->r * cy->r;
	return (sq_equation(coef[0], coef[1], coef[2], t));
}

static float	t_side_limit(float t, t_ray ray, t_cy *cy, t_vec3 p_bottom)
{
	t_vec3 t_point;

	if (t > ACC)
	{
		t_point = p_trans(ray.o, ray.n, t);
		if (v_dot(cy->n, v_minus(t_point, cy->p_top)) >= 0 && \
			v_dot(cy->n, v_minus(t_point, p_bottom)) <= 0)
			return (t);
	}
	return (INFINITY);
}

float			intersect_cylinder(t_ray ray, t_cy *cy)
{
	t_vec3 p_bottom;

	cy->p_top = p_trans(cy->o, cy->n, -cy->h / 2);
	p_bottom = p_trans(cy->o, cy->n, cy->h / 2);
	if (!intersect_side(cy->t, ray, cy))
		return (-1);
	cy->t[0] = t_side_limit(cy->t[0], ray, cy, p_bottom);
	cy->t[1] = t_side_limit(cy->t[1], ray, cy, p_bottom);
	cy->t[0] = fminf(cy->t[0], cy->t[1]);
	if (cy->t[0] == INFINITY)
		return (-1);
	cy->t[1] = -1;
	cy->t[2] = -1;
	cy->t[3] = -1;
	return (cy->t[0]);
}
