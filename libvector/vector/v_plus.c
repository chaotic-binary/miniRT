/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_plus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:38:44 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 16:42:55 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/vector.h"

t_vec3	v_plus(t_vec3 u, t_vec3 v)
{
	t_vec3 res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}
