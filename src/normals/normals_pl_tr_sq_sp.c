/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals_pl_tr_sq_sp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:22:40 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/29 19:07:48 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

t_vec3	n_plane(t_pl *pl)
{
	return (pl->n);
}

t_vec3	n_sphere(t_sp *sp)
{
	return (normal(sp->o, sp->t_point));
}

t_vec3	n_triangle(t_tr *tr)
{
	return (v_normalize(v_cross(v_minus(tr->v1, tr->v0), \
								v_minus(tr->v2, tr->v0))));
}

t_vec3	n_square(t_sq *sq)
{
	return (sq->n);
}
