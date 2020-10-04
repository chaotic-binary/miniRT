/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 12:38:54 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/02 00:11:13 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../Includes/exit.h"
#include "../../Includes/parser.h"
#include "../../Includes/get_next_line.h"
#include "../../minilibx_mms/mlx.h"

static void	correct_resolution(t_scene *scene, void *mlx)
{
	int screen_x;
	int screen_y;

	mlx_get_screen_size(mlx, &screen_x, &screen_y);
	if (scene->resolution[X] > screen_x)
		scene->resolution[X] = screen_x;
	if (scene->resolution[Y] > screen_y)
		scene->resolution[Y] = screen_y;
}

static void	check_data(t_scene *scene)
{
	if (!scene->cams)
		free_and_exit(ERR_NO_CAM);
	if (!(scene->resolution[2]))
		free_and_exit(ERR_NO_R);
	correct_resolution(scene, scene->window.mlx);
}

static void	tab_to_space(char *s)
{
	while (*s++)
	{
		if (*s == '\t')
			*s = ' ';
	}
}

static int	parse_line(char **line, t_scene *scene, int line_num)
{
	int				i;
	char			**args;
	const t_parser	parse[] = { { "R", parse_resolution }, \
		{ "c", parse_camera }, { "l", parse_light }, { "A", parse_ambient },\
		{ "sp", parse_sphere }, { "pl", parse_plane }, { "sq", parse_square }, \
		{ "cy", parse_cylinder }, { "tr", parse_triangle },  \
		{ "cu", parse_cube}, { "py", parse_pyramid}, { "co", parse_cone}, };

	tab_to_space(*line);
	args = ft_split(*line, ' ');
	free(*line);
	if (!args)
		return (free_and_exit(ERRNO));
	i = -1;
	while (++i < 12)
	{
		if (!(ft_memcmp(args[0], parse[i].id, (ft_strlen(parse[i].id) + 1))))
		{
			parse[i].parse(args, scene, line_num);
			free_arr(args);
			return (1);
		}
	}
	free_arr(args);
	return (0);
}

void		parse_file(char *file, t_scene *scene)
{
	int		ret;
	int		fd;
	int		line_num;
	char	*line;

	fd = open(file, O_RDONLY);
	line_num = 0;
	while ((ret = get_next_line(fd, &line)) != 0 || *line)
	{
		++line_num;
		if (line[0] != '\0' && line[0] != '#')
		{
			if (!parse_line(&line, scene, line_num))
			{
				close(fd);
				free_and_exit(line_num);
			}
		}
		else
			free(line);
	}
	free(line);
	close(fd);
	check_data(scene);
}
