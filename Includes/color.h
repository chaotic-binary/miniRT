/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 01:11:50 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:44:10 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_argb {
	float		a;
	float		r;
	float		g;
	float		b;
}				t_argb;

t_argb			color_new(float a, float r, float g, float b);
unsigned		int_color(t_argb color);
t_argb			argb_color(int color);
unsigned		color_average(t_argb *color, int n);
t_argb			color_divn(t_argb color, float n);
t_argb			color_multn(t_argb color, float n);
t_argb			color_mult(t_argb color1, t_argb color2);
t_argb			color_plus(t_argb u, t_argb v);
void			check_color_range(t_argb *color);
t_argb			filter_sepia(t_argb color);

#endif
