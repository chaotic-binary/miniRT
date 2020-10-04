/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_with_caps.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:03:30 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/03 23:12:20 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

static float	closest_t(float *t, int n)
{
	float	closest;
	int		i;
	int		m;

	closest = INFINITY;
	i = -1;
	m = -1;
	while (++i < n)
	{
		if (t[i] > ACC && closest > t[i])
		{
			closest = t[i];
			m = i;
		}
	}
	if (closest == INFINITY)
		return (-1);
	i = -1;
	while (++i < n)
	{
		if (i != m)
			t[i] = -1;
	}
	return (closest);
}

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

static float	intersect_disc(t_ray ray, t_vec3 cy_p, t_vec3 cy_n, float r)
{
	t_pl	pl;
	t_vec3	t_point;
	t_vec3	b;
	float	t;

	pl.o = cy_p;
	pl.n = cy_n;
	t = intersect_plane(ray, &pl);
	if (t > ACC)
	{
		t_point = p_trans(ray.o, ray.n, t);
		b = v_minus(t_point, cy_p);
		if (v_dot(b, b) < r * r)
			return (t);
	}
	return (INFINITY);
}

float			intersect_cylinder_caps(t_ray ray, t_cy *cy)
{
	t_vec3 p_bottom;

	cy->p_top = p_trans(cy->o, cy->n, -cy->h / 2);
	p_bottom = p_trans(cy->o, cy->n, cy->h / 2);
	cy->t[0] = INFINITY;
	cy->t[1] = INFINITY;
	intersect_side(cy->t, ray, cy);
	cy->t[0] = t_side_limit(cy->t[0], ray, cy, p_bottom);
	cy->t[1] = t_side_limit(cy->t[1], ray, cy, p_bottom);
	cy->t[2] = intersect_disc(ray, cy->p_top, cy->n, cy->r);
	cy->t[3] = intersect_disc(ray, p_bottom, cy->n, cy->r);
	return (closest_t(cy->t, 4));
}
