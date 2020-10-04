/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:10:55 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/22 00:11:27 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

float	intersect_plane(t_ray ray, t_pl *pl)
{
	float	d;
	float	t;
	t_vec3	pr;

	d = v_dot(pl->n, ray.n);
	if (fabs(d) > 0)
	{
		pr = v_minus(pl->o, ray.o);
		t = v_dot(pr, pl->n) / d;
		if (t > ACC)
			return (t);
	}
	return (0);
}
