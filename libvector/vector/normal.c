/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:28:35 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 16:42:37 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/vector.h"

t_vec3	normal(t_vec3 u, t_vec3 v)
{
	return (v_normalize(v_minus(v, u)));
}
