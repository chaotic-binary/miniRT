/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:46:57 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/03 23:19:56 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include "scene.h"
# include <fcntl.h>
# include <unistd.h>

# include <time.h>

# define BMP_HEADER_SIZE 14
# define BMP_INFO_SIZE (OFFSET - BMP_HEADER_SIZE)
# define OFFSET 54
# define PLANES 1

void	save_bmp(int *res, t_img *data);

#endif
