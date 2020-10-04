/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argb_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:15:40 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:44 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

t_argb	argb_color(int color)
{
	t_argb res;

	res.a = (float)((color >> 24) & 0xff) / 255;
	res.r = (float)((color >> 16) & 0xff) / 255;
	res.g = (float)((color >> 8) & 0xff) / 255;
	res.b = (float)(color & 0xff) / 255;
	return (res);
}
