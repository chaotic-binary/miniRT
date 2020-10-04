/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:46:10 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:57 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

t_argb	color_mult(t_argb color1, t_argb color2)
{
	t_argb res;

	res.a = color1.a * color2.a;
	res.r = color1.r * color2.r;
	res.g = color1.g * color2.g;
	res.b = color1.b * color2.b;
	return (res);
}
