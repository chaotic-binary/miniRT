/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_average.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:07:36 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:51 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

unsigned	color_average(t_argb *color, int n)
{
	t_argb	average;
	int		i;

	average = color_new(0, 0, 0, 0);
	i = -1;
	while (++i < n)
	{
		average.a += color[i].a;
		average.r += color[i].r;
		average.g += color[i].g;
		average.b += color[i].b;
	}
	average.a /= n;
	average.r /= n;
	average.g /= n;
	average.b /= n;
	return (int_color(average));
}
