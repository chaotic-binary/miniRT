/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:45:00 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:42:03 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

t_argb	color_plus(t_argb u, t_argb v)
{
	t_argb res;

	res.a = u.a + v.a;
	res.r = u.r + v.r;
	res.g = u.g + v.g;
	res.b = u.b + v.b;
	check_color_range(&res);
	return (res);
}
