/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_normalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:35:09 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 16:42:59 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/vector.h"

t_vec3	v_normalize(t_vec3 v)
{
	t_vec3		res;
	float		div;

	div = v_mod(v);
	if (div)
		res = v_divn(v, div);
	else
		res = v;
	return (res);
}
