/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:18:47 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:42:33 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"
#include "../../Includes/exit.h"

static t_argb	pixel_color(char *img, t_img *data, int x, int y)
{
	char	*dst;

	dst = img + (y * data->line_length + x \
									* (data->bits_per_pixel >> 3));
	return (argb_color(*(unsigned int *)dst));
}

static void		fill_colors(t_argb *color, char *img, t_img *data, int *pixel)
{
	color[0] = pixel_color(img, data, pixel[X], pixel[Y]);
	color[1] = pixel_color(img, data, pixel[X] + 0.9, pixel[Y] + 0.9);
	color[2] = pixel_color(img, data, pixel[X] + 0.9, pixel[Y] - 0.5);
	color[3] = pixel_color(img, data, pixel[X] - 0.5, pixel[Y] + 0.9);
	color[4] = pixel_color(img, data, pixel[X] - 0.5, pixel[Y] - 0.5);
	color[5] = pixel_color(img, data, pixel[X], pixel[Y] - 0.5);
	color[6] = pixel_color(img, data, pixel[X], pixel[Y] + 0.9);
	color[7] = pixel_color(img, data, pixel[X] - 0.5, pixel[Y]);
	color[8] = pixel_color(img, data, pixel[X] + 0.9, pixel[Y]);
}

void			antialiasing(t_scene *scene, t_img *data)
{
	char		*tmp;
	const int	size = data->line_length * scene->resolution[Y];
	int			pixel[2];
	t_argb		color[9];

	if (!(tmp = malloc(size)))
		free_and_exit(ERRNO);
	ft_memcpy(tmp, data->addr, size);
	pixel[Y] = 0;
	while (++pixel[Y] < scene->resolution[Y] - 1)
	{
		pixel[X] = 0;
		while (++pixel[X] < scene->resolution[X] - 1)
		{
			fill_colors(color, tmp, data, pixel);
			my_mlx_pixel_put(data, pixel, color_average(color, 9));
		}
	}
	free(tmp);
}
