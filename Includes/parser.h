/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:01:44 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/28 20:41:21 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "scene.h"

typedef struct	s_parser
{
	char		*id;
	void		(*parse)(char **, t_scene *, int);
}				t_parser;

void			parse_file(char *file, t_scene *scene);
void			parse_resolution(char **args, t_scene *scene, int line_num);
void			parse_ambient(char **args, t_scene *scene, int line_num);
void			parse_camera(char **args, t_scene *scene, int line_num);
void			parse_cylinder(char **args, t_scene *scene, int line_num);
void			parse_light(char **args, t_scene *scene, int line_num);
void			parse_plane(char **args, t_scene *scene, int line_num);
void			parse_sphere(char **args, t_scene *scene, int line_num);
void			parse_square(char **args, t_scene *scene, int line_num);
void			parse_triangle(char **args, t_scene *scene, int line_num);
void			parse_cone(char **args, t_scene *scene, int line_num);
void			parse_cube(char **args, t_scene *scene, int line_num);
void			parse_pyramid(char **args, t_scene *scene, int line_num);

void			parse_color(char *arg, t_argb *color, char **args, \
							int line_num);
void			parse_coordinates(char *arg, t_vec3 *point, char **args,\
							int line_num);

int				is_uint(char *w);
int				is_float(char *w, int neg);
int				arg_num(char **args);
int				check_float_range(float n, float min, float max);
int				check_norm(t_vec3 *v);

#endif
