/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 00:12:05 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:15:48 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

static float	t_side_limit(float t, t_ray ray, t_cy *co)
{
	t_vec3 t_point;
	t_vec3 p_bottom;

	if (t > ACC)
	{
		t_point = p_trans(ray.o, ray.n, t);
		p_bottom = p_trans(co->o, co->n, co->h);
		if (v_dot(co->n, v_minus(t_point, co->o)) >= 0 && \
			v_dot(co->n, v_minus(t_point, p_bottom)) <= 0)
			return (t);
	}
	return (INFINITY);
}

float			intersect_cone(t_ray ray, t_cy *co)
{
	float	k;
	float	coef[3];
	t_vec3	x;

	co->t[2] = INFINITY;
	co->t[3] = INFINITY;
	k = co->r / co->h;
	x = v_minus(ray.o, co->o);
	coef[0] = v_dot(ray.n, ray.n) - (1 + k * k) * pow(v_dot(ray.n, co->n), 2);
	coef[1] = (v_dot(ray.n, x) - (1 + k * k) * \
				v_dot(ray.n, co->n) * v_dot(x, co->n)) * 2;
	coef[2] = v_dot(x, x) - (1 + k * k) * pow(v_dot(x, co->n), 2);
	if (!sq_equation(coef[0], coef[1], coef[2], co->t))
		return (-1);
	co->t[0] = t_side_limit(co->t[0], ray, co);
	co->t[1] = t_side_limit(co->t[1], ray, co);
	co->t[2] = -1;
	co->t[3] = -1;
	co->t[0] = fminf(co->t[0], co->t[1]);
	co->t[1] = -1;
	if (co->t[0] > ACC)
		return (co->t[0]);
	return (-1);
}
