/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 01:11:50 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/22 17:41:45 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>

typedef struct	s_vec3 {
	float		y;
	float		x;
	float		z;
}				t_vec3;

float			v_dot(t_vec3 u, t_vec3 v);
t_vec3			v_cross(t_vec3 u, t_vec3 v);
t_vec3			v_plus(t_vec3 u, t_vec3 v);
t_vec3			v_minus(t_vec3 u, t_vec3 v);
t_vec3			v_divn(t_vec3 u, float n);
t_vec3			v_multn(t_vec3 u, float n);
t_vec3			v_mult(t_vec3 u, t_vec3 v);
t_vec3			v_new(float x, float y, float z);
float			v_mod(t_vec3 v);
t_vec3			v_inv(t_vec3 v);
float			v_dist(t_vec3 v, t_vec3 u);
t_vec3			v_normalize(t_vec3 v);
t_vec3			normal(t_vec3 u, t_vec3 v);
t_vec3			p_trans(t_vec3 p, t_vec3 n, float dist);

#endif
