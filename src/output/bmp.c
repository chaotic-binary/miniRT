/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamesha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:33:30 by ttamesha          #+#    #+#             */
/*   Updated: 2020/10/03 23:06:46 by ttamesha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/bmp.h"
#include "../Includes/exit.h"

/*
** works good, but uses forbidden function
*/

static void	fill_filename(char *buff)
{
	time_t		t;
	struct tm	*tm;
	size_t		len;

	time(&t);
	ft_bzero(buff, 50);
	tm = localtime(&t);
	ft_strcpy(buff, "Image_");
	len = strftime(buff + 6, 39, "%F_%T", tm);
	ft_strcpy(buff + 6 + len, ".bmp");
}

/*
** safe version
** static void	fill_filename(char *buff)
** {
** 	static int	n = 0;
** 	int			len;
** 	char		*n_str;
**
** 	ft_bzero(buff, 50);
** 	ft_strcpy(buff, "Image_");
** 	len = ft_strlen(__TIME__);
** 	ft_strcpy(buff + 6, __TIME__);
** 	ft_strcpy(buff + 6 + len, "_");
** 	n_str = ft_itoa(n);
** 	ft_strcpy(buff + 7 + len, n_str);
** 	free(n_str);
** 	len += countdigits(n);
** 	ft_strcpy(buff + 7 + len, ".bmp");
** 	++n;
** }
*/

static void	fill_img(char *img, int *resolution, t_img *data, int imgsize)
{
	int y;

	if (resolution[X] % 64)
	{
		y = -1;
		while (++y < resolution[Y])
			ft_memcpy(img + y * resolution[X] * sizeof(int), data->addr + \
					data->line_length * y, resolution[X] * sizeof(int));
	}
	else
		ft_memcpy(img, data->addr, imgsize);
}

void		save_bmp(int *resolution, t_img *data)
{
	int			fd;
	char		buff[50];
	char		*bmp;
	const int	imgsize = resolution[X] * resolution[Y] * 4;
	const int	filesize = imgsize + OFFSET;

	if (!(bmp = malloc(filesize)))
		free_and_exit(ERRNO);
	ft_bzero(bmp, OFFSET);
	ft_memcpy(bmp, "BM", 2);
	*(unsigned int *)(bmp + 2) = filesize;
	*(unsigned int *)(bmp + 10) = OFFSET;
	*(unsigned int *)(bmp + 14) = BMP_INFO_SIZE;
	*(unsigned int *)(bmp + 18) = resolution[X];
	*(unsigned int *)(bmp + 22) = -resolution[Y];
	*(unsigned short *)(bmp + 26) = PLANES;
	*(unsigned short *)(bmp + 28) = (short)data->bits_per_pixel;
	fill_img(&bmp[OFFSET], resolution, data, imgsize);
	fill_filename(buff);
	fd = open(buff, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(fd, bmp, filesize);
	free(bmp);
	close(fd);
	write(1, "Image saved\n", 12);
}
