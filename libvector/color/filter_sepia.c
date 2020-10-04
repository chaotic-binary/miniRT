/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_sepia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:54:05 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:42:06 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

t_argb	filter_sepia(t_argb color)
{
	t_argb	res;

	res.r = (color.r * 0.393) + (color.g * 0.769) + (color.b * 0.189);
	res.g = (color.r * 0.349) + (color.g * 0.686) + (color.b * 0.168);
	res.b = (color.r * 0.272) + (color.g * 0.534) + (color.b * 0.131);
	check_color_range(&res);
	return (res);
}
