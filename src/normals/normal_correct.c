/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_correct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:51:15 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 23:51:54 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

void		normal_correct(t_vec3 *n, t_vec3 ray_n)
{
	if (v_dot(*n, ray_n) > 0)
		*n = v_inv(*n);
}
