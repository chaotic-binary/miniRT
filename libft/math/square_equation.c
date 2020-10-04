/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_equation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:10:21 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 13:54:43 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	sq_equation(float a, float b, float c, float *t)
{
	float d;
	float sqrtfd;

	if (a != 0)
	{
		d = b * b - 4 * a * c;
		if (d >= 0)
		{
			sqrtfd = sqrt(d);
			t[0] = (-b + sqrtfd) / (2 * a);
			t[1] = (-b - sqrtfd) / (2 * a);
			return (1);
		}
	}
	return (0);
}
