/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_multn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:44:34 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:59 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

t_argb	color_multn(t_argb color, float n)
{
	t_argb res;

	res.a = color.a * n;
	res.r = color.r * n;
	res.g = color.g * n;
	res.b = color.b * n;
	return (res);
}
