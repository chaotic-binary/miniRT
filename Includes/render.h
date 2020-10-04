/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 21:03:53 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/03 23:12:48 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "scene.h"
# include "../minilibx_mms/mlx.h"

# define PI 3.14159265
# define ACC 0.0001

# ifndef SHINE
#  define SHINE 0
# endif

float		intersect_sphere(t_ray ray, t_sp *sp);
float		intersect_triangle(t_ray ray, t_tr *tr);
float		intersect_square(t_ray ray, t_sq *sq);
float		intersect_plane(t_ray ray, t_pl *pl);
float		intersect_cylinder(t_ray ray, t_cy *cy);
float		intersect_cylinder_caps(t_ray ray, t_cy *cy);
float		intersect_cone(t_ray ray, t_cy *co);

t_vec3		n_plane(t_pl *pl);
t_vec3		n_sphere(t_sp *sp);
t_vec3		n_triangle(t_tr *tr);
t_vec3		n_square(t_sq *sq);
t_vec3		n_cylinder(t_cy *cy);
t_vec3		n_cone(t_cy *co);
void		normal_correct(t_vec3 *n, t_vec3 ray_n);

void		set_camera(int x_res, int y_res, t_c *cam, t_ray *ray);
void		put_ray(int *pixel, t_ray *ray, t_c *cam);
void		my_mlx_pixel_put(t_img *data, int *pixel, unsigned int color);
unsigned	trace_ray(t_scene *scene, t_list *objs, t_ray ray, int filter);
void		antialiasing(t_scene *scene, t_img *data);

#endif
