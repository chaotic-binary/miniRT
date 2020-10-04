/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:41:53 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/29 19:27:51 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/render.h"

void			put_ray(int *pixel, t_ray *ray, t_c *cam)
{
	t_vec3 px;
	t_vec3 py;
	t_vec3 ray_d;

	px = v_multn(cam->nx, pixel[Y]);
	py = v_multn(cam->ny, pixel[X]);
	ray_d = v_plus(px, py);
	ray_d = v_plus(ray_d, cam->v[0]);
	ray->n = normal(ray->o, ray_d);
}

void			my_mlx_pixel_put(t_img *data, int *pixel, unsigned int color)
{
	char	*dst;

	dst = data->addr + (pixel[Y] * data->line_length + pixel[X] \
									* (data->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}

static t_vec3	screen_center(int x_half, int fov, t_vec3 cam_pos, t_vec3 cam_n)
{
	float q;
	float h;

	q = (x_half) / sin(((fov >> 1) * PI) / 180);
	h = sqrt(q * q - pow(x_half, 2));
	return (p_trans(cam_pos, cam_n, h));
}

void			set_camera(int x_half, int y_half, t_c *cam, t_ray *ray)
{
	t_vec3 center;
	t_vec3 axis;
	t_vec3 ox;
	t_vec3 oy;

	center = screen_center(x_half, cam->fov, cam->pos, cam->n);
	axis = (fabs(cam->n.y) == 1) ? v_new(0, 0, 1) : v_new(0, 1, 0);
	ox = v_normalize(v_cross(cam->n, axis));
	oy = v_normalize(v_cross(cam->n, ox));
	ox = v_multn(ox, x_half);
	oy = v_multn(oy, y_half);
	cam->v[0] = v_plus(v_plus(ox, oy), center);
	cam->v[1] = v_plus(v_plus(v_inv(ox), oy), center);
	cam->v[2] = v_plus(v_plus(v_inv(ox), v_inv(oy)), center);
	cam->v[3] = v_plus(v_plus(ox, v_inv(oy)), center);
	cam->ny = normal(cam->v[0], cam->v[1]);
	cam->nx = normal(cam->v[0], cam->v[3]);
	ray->o = cam->pos;
}
