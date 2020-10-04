/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:05:01 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/22 00:33:34 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

float	intersect_square(t_ray ray, t_sq *sq)
{
	float	t;
	float	h[2];
	t_vec3	e1;
	t_vec3	e2;
	t_vec3	op;

	t = intersect_plane(ray, (t_pl *)sq);
	if (!t)
		return (0);
	e1 = v_normalize(v_cross(sq->n, fabs(sq->n.y) == 1 ? \
						v_new(1, 0, 0) : v_new(0, 1, 0)));
	e2 = v_normalize(v_cross(sq->n, e1));
	op = v_minus(v_plus(ray.o, v_multn(ray.n, t)), sq->o);
	h[0] = fabs(v_dot(op, e1));
	h[1] = fabs(v_dot(op, e2));
	if (h[0] > sq->h / 2 - ACC || h[1] > sq->h / 2 - ACC)
		return (0);
	else
		return (t);
}
