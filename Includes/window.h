/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:46:49 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/15 01:52:57 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "scene.h"
# include "../minilibx_mms/mlx.h"

# define KEY_ESC			(0x35)
# define KEY_RIGHT_ARROW	(0x7C)
# define KEY_LEFT_ARROW		(0x7B)
# define KEY_S				(0x01)

void	open_window(t_scene *scene, t_c *cam);

#endif
