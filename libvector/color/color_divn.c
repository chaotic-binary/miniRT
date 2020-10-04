/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_divn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 19:49:44 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:54 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/color.h"

t_argb	color_divn(t_argb color, float n)
{
	t_argb res;

	res.a = color.a / n;
	res.r = color.r / n;
	res.g = color.g / n;
	res.b = color.b / n;
	return (res);
}
