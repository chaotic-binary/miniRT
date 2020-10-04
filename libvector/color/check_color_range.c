/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:27:14 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:48 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

void	check_color_range(t_argb *color)
{
	if (color->a > 1.0)
		color->a = 1.0;
	if (color->r > 1.0)
		color->r = 1.0;
	if (color->g > 1.0)
		color->g = 1.0;
	if (color->b > 1.0)
		color->b = 1.0;
}
