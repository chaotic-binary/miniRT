/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:44:12 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:42:08 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

unsigned	int_color(t_argb color)
{
	return (((unsigned char)(color.a * 255) << 24) +\
			((unsigned char)(color.r * 255) << 16) +\
			((unsigned char)(color.g * 255) << 8) +\
			(unsigned char)(color.b * 255));
}
