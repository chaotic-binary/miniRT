/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:03:31 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 16:43:03 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/vector.h"

t_vec3	v_new(float x, float y, float z)
{
	t_vec3 point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
