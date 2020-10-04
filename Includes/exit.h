/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:47:12 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/22 17:15:04 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <errno.h>
# include <string.h>
# include "scene.h"

# define ERRNO -1
# define ERR_FILETYPE -2
# define ERR_DEBUG -3
# define ERR_ARG_NUMBER -4
# define ERR_SEC_ARG -5
# define ERR_DOUBLE_A -6
# define ERR_DOUBLE_R -7
# define ERR_NO_R -8
# define ERR_NO_CAM -9
# define ERR_COL -10
# define ERR_COORD -11
# define ERR_ZERO_SIZE -12
# define ERR_WINDOW -13

int	exit_with_errno(void);
int	exit_program(void);
int	close_window(t_mlx *window);
int	exit_custom_err(int error_num);
int	free_and_exit(int error_num);

int	parse_line_exit(char *line, int fd, int error_num);
int	parse_vec_exit(char **args, char **val, int error_num, int obj);
int	parser_exit(char **args, int error_num);

#endif
