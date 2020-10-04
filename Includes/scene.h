/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:18:35 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/29 19:05:04 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../libft/libft.h"
# include "vector.h"
# include "color.h"

# define X 0
# define Y 1

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_ray
{
	t_vec3			o;
	t_vec3			n;
}					t_ray;

typedef struct		s_c
{
	t_vec3			pos;
	t_vec3			n;
	int				fov;
	t_vec3			v[4];
	t_vec3			nx;
	t_vec3			ny;
	t_img			img;
	int				filter;
}					t_c;

typedef struct		s_a
{
	int				set;
	float			ratio;
	t_argb			color;
}					t_a;

typedef struct		s_l
{
	t_vec3			o;
	t_vec3			n;
	t_argb			color;
	float			ratio;
	int				type;
}					t_l;

typedef struct		s_sp
{
	float			(*intersect)(t_ray, struct s_sp *);
	t_vec3			(*normal)(struct s_sp *);
	t_argb			color;
	t_vec3			t_point;
	t_vec3			o;
	float			r;
}					t_sp;

typedef struct		s_pl
{
	float			(*intersect)(t_ray, struct s_pl *);
	t_vec3			(*normal)(struct s_pl *);
	t_argb			color;
	t_vec3			t_point;
	t_vec3			n;
	t_vec3			o;
}					t_pl;

typedef struct		s_tr
{
	float			(*intersect)(t_ray, struct s_tr *);
	t_vec3			(*normal)(struct s_tr *);
	t_argb			color;
	t_vec3			t_point;
	t_vec3			v0;
	t_vec3			v1;
	t_vec3			v2;
}					t_tr;

typedef struct		s_sq
{
	float			(*intersect)(t_ray, struct s_sq *);
	t_vec3			(*normal)(struct s_sq *);
	t_argb			color;
	t_vec3			t_point;
	t_vec3			n;
	t_vec3			o;
	float			h;
}					t_sq;

typedef struct		s_cy
{
	float			(*intersect)(t_ray, struct s_cy *);
	t_vec3			(*normal)(struct s_cy *);
	t_argb			color;
	t_vec3			t_point;
	t_vec3			n;
	t_vec3			o;
	float			h;
	float			r;
	t_vec3			p_top;
	float			t[4];
}					t_cy;

typedef struct		s_scene
{
	int				resolution[3];
	t_a				ambient;
	t_dlist			*cams;
	t_list			*objs;
	t_list			*lights;
	t_mlx			window;
}					t_scene;

typedef struct		s_obj
{
	float			(*intersect)(t_ray, struct s_obj *);
	t_vec3			(*normal)(struct s_obj *);
	t_argb			color;
	t_vec3			t_point;
}					t_obj;

#endif
