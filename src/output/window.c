/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:20:05 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/02 22:51:35 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/window.h"
#include "../Includes/exit.h"
#include "../Includes/bmp.h"

static t_c	*get_cam(t_dlist *cams, int keycode)
{
	static t_dlist *current = NULL;

	if (!current)
		current = cams;
	if (keycode == KEY_RIGHT_ARROW)
	{
		if (current->next)
			current = current->next;
		else
			current = cams;
	}
	if (keycode == KEY_LEFT_ARROW)
	{
		if (current->prev)
			current = current->prev;
		else
			current = ft_dlstlast(cams);
	}
	return ((t_c *)current->content);
}

static int	button_action(int keycode, t_scene *scene)
{
	t_c *cam;

	if (keycode == KEY_ESC)
		close_window(&scene->window);
	else if (keycode == KEY_RIGHT_ARROW || keycode == KEY_LEFT_ARROW)
	{
		cam = get_cam(scene->cams, keycode);
		mlx_clear_window(scene->window.mlx, scene->window.win);
		mlx_put_image_to_window(scene->window.mlx, scene->window.win, \
								cam->img.img, 0, 0);
	}
	else if (keycode == KEY_S)
	{
		cam = get_cam(scene->cams, keycode);
		save_bmp(scene->resolution, &cam->img);
	}
	return (1);
}

void		open_window(t_scene *scene, t_c *cam)
{
	scene->window.win = mlx_new_window(scene->window.mlx, scene->resolution[X],\
						scene->resolution[Y], "miniRT by ttamesha");
	if (!(scene->window.win))
		free_and_exit(ERR_WINDOW);
	mlx_put_image_to_window(scene->window.mlx, scene->window.win, \
							cam->img.img, 0, 0);
	write(1, "Press s for screenshot, ", 24);
	write(1, "right and left arrows to change camera, \n", 41);
	write(1, "esc for exit\n", 13);
	mlx_hook(scene->window.win, 2, 1L << 0, button_action, scene);
	mlx_hook(scene->window.win, 17, 1L << 17, close_window, &scene->window);
	mlx_loop(scene->window.mlx);
}
