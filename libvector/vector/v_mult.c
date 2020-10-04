/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_mult.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:38:06 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 16:43:09 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/vector.h"

t_vec3	v_mult(t_vec3 u, t_vec3 v)
{
	t_vec3 res;

	res.x = u.x * v.x;
	res.y = u.y * v.y;
	res.z = u.z * v.z;
	return (res);
}
