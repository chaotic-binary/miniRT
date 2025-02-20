/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_inv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:36:18 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 16:43:24 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/vector.h"

t_vec3	v_inv(t_vec3 v)
{
	t_vec3 res;

	res.x = -v.x;
	res.y = -v.y;
	res.z = -v.z;
	return (res);
}
