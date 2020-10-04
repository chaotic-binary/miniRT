/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:28:41 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/22 17:18:14 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/exit.h"
#include "../libft/libft.h"

int	parser_exit(char **args, int error_num)
{
	free_arr(args);
	malloc_c(0);
	if (error_num == ERRNO)
		return (exit_with_errno());
	else if (error_num == ERR_DOUBLE_R)
		write(1, "Error\nDouble entries for Resolution\n", 36);
	else if (error_num == ERR_DOUBLE_A)
		write(1, "Error\nDouble entries for Ambient\n", 33);
	else if (error_num == ERR_ZERO_SIZE)
		write(1, "Error\nObject of 0 size doesn't make sense\n", 42);
	else
	{
		write(1, "Error\nwhile parsing line ", 25);
		ft_putnbr_fd(error_num, 1);
		write(1, "\n", 1);
	}
	exit(-1);
}

int	parse_vec_exit(char **args, char **val, int error_num, int line_num)
{
	free_arr(val);
	free_arr(args);
	malloc_c(0);
	if (error_num == ERR_COL)
	{
		write(1, "Error\nwhile parsing color in line ", 34);
		ft_putnbr_fd(line_num, 1);
		write(1, "\n", 1);
	}
	else if (error_num == ERR_COORD)
	{
		write(1, "Error\nwhile parsing coordinates in line ", 41);
		ft_putnbr_fd(line_num, 1);
		write(1, "\n", 1);
	}
	exit(-1);
}

int	parse_line_exit(char *line, int fd, int error_num)
{
	if (line)
		free(line);
	close(fd);
	return ((free_and_exit(error_num)));
}
