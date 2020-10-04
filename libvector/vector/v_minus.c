/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_minus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:37:49 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 16:43:21 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/vector.h"

t_vec3	v_minus(t_vec3 from, t_vec3 v)
{
	t_vec3 res;

	res.x = from.x - v.x;
	res.y = from.y - v.y;
	res.z = from.z - v.z;
	return (res);
}
