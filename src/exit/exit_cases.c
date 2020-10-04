/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:47:05 by ttamesha          #+#    #+#             */
/*   Updated: 2020/09/19 00:57:48 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/exit.h"
#include "../../libft/libft.h"
#include "../../minilibx_mms/mlx.h"

int	exit_with_errno(void)
{
	ft_putendl_fd(strerror(errno), 1);
	exit(errno);
}

int	free_and_exit(int error_num)
{
	malloc_c(0);
	if (error_num == ERRNO)
		return (exit_with_errno());
	else
		return (exit_custom_err(error_num));
}

int	exit_custom_err(int error_num)
{
	if (error_num == ERR_FILETYPE)
		write(1, "Error\nIncorrect file type, .rt file required\n", 45);
	else if (error_num == ERR_DEBUG)
		write(1, "Error\nSomething went wrong\n", 27);
	else if (error_num == ERR_ARG_NUMBER)
		write(1, "Error\nWrong number of arguments\n", 32);
	else if (error_num == ERR_SEC_ARG)
		write(1, "Error\nSecond argument can be -s or --save\n", 42);
	else if (error_num == ERR_NO_CAM)
		write(1, "Error\nNo cameras\n", 17);
	else if (error_num == ERR_WINDOW)
		write(1, "Error\nFailed to create window\n", 30);
	else if (error_num == ERR_NO_R)
		write(1, "Error\nNo entry for resolution\n", 30);
	else
	{
		write(1, "Error\nIncorrect first symbol on line ", 37);
		ft_putnbr_fd(error_num, 1);
		write(1, "\n", 1);
	}
	exit(-1);
}

int	close_window(t_mlx *window)
{
	mlx_destroy_window(window->mlx, window->win);
	return (exit_program());
}

int	exit_program(void)
{
	malloc_c(0);
	write(1, "Good Bye!\n", 10);
	exit(0);
}
