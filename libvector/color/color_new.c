/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:41:26 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:42:01 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

t_argb	color_new(float a, float r, float g, float b)
{
	t_argb color;

	color.a = a;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
