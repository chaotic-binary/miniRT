/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:09:26 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 17:41:13 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

float	intersect_sphere(t_ray ray, t_sp *sp)
{
	t_vec3	k;
	float	b;
	float	c;
	float	d;
	float	sqrtfd;

	k = v_minus(ray.o, sp->o);
	b = v_dot(k, ray.n);
	c = v_dot(k, k) - (sp->r * sp->r);
	d = b * b - c;
	if (d < 0)
		return (0);
	sqrtfd = sqrt(d);
	c = -b + sqrtfd;
	d = -b - sqrtfd;
	b = fminf(c, d);
	if (b < 0)
		b = fmaxf(c, d);
	if (b > ACC)
		return (b);
	return (0);
}
