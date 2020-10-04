/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:40:24 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/02 22:51:04 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/window.h"
#include "../../Includes/parser.h"
#include "../../Includes/render.h"
#include "../../Includes/bmp.h"
#include "../../Includes/exit.h"

static void		render_current_cam(t_scene *scene, t_c *cam)
{
	int		pixel[2];
	t_ray	ray;

	cam->img.img = mlx_new_image(scene->window.mlx, scene->resolution[X], \
													scene->resolution[Y]);
	cam->img.addr = mlx_get_data_addr(cam->img.img, &cam->img.bits_per_pixel, \
						&cam->img.line_length, &cam->img.endian);
	set_camera(scene->resolution[X] >> 1, scene->resolution[Y] >> 1, cam, &ray);
	pixel[Y] = -1;
	while (++pixel[Y] < scene->resolution[Y])
	{
		pixel[X] = -1;
		while (++pixel[X] < scene->resolution[X])
		{
			put_ray(pixel, &ray, cam);
			my_mlx_pixel_put(&cam->img, pixel, \
							(trace_ray(scene, scene->objs, ray, cam->filter)));
		}
	}
	if (cam->filter & 2)
		antialiasing(scene, &cam->img);
}

static void		render_all_cams(t_scene *scene, t_dlist *cams)
{
	write(1, "Rendering...\n", 13);
	while (cams)
	{
		render_current_cam(scene, cams->content);
		cams = cams->next;
	}
}

static void		parse_args(int ac, char **av, int *save)
{
	if (ac < 2 || ac > 3)
		exit_custom_err(ERR_ARG_NUMBER);
	if ((ft_memcmp(av[1] + (ft_strlen(av[1]) - 3), ".rt", 3)))
		exit_custom_err(ERR_FILETYPE);
	if (ac == 3)
	{
		if (ft_memcmp(av[2], "--save", 7) && ft_memcmp(av[2], "-s", 3))
			exit_custom_err(ERR_SEC_ARG);
		*save = 1;
	}
}

static t_scene	*scene_init(void)
{
	t_scene *scene;

	if (!(scene = (t_scene *)malloc_c(sizeof(t_scene))))
		exit_with_errno();
	scene->resolution[0] = 0;
	scene->resolution[1] = 0;
	scene->resolution[2] = 0;
	scene->ambient.ratio = 0.0;
	scene->ambient.set = 0;
	scene->ambient.color = color_new(0, 0, 0, 0);
	scene->cams = NULL;
	scene->objs = NULL;
	scene->lights = NULL;
	scene->window.mlx = mlx_init();
	return (scene);
}

int				main(int ac, char **av)
{
	t_scene	*scene;
	int		save;

	save = 0;
	parse_args(ac, av, &save);
	parse_file(av[1], (scene = scene_init()));
	if (!save)
	{
		render_all_cams(scene, scene->cams);
		open_window(scene, scene->cams->content);
	}
	else
	{
		render_current_cam(scene, scene->cams->content);
		save_bmp(scene->resolution, &((t_c *)(scene->cams->content))->img);
		exit_program();
	}
}
