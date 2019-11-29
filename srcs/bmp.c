/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:39:55 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 18:55:12 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void int_as_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int write_header(int fd, int filesize, t_cub3d *t)
{
	unsigned char	*bmpfileheader;

	bmpfileheader = ft_calloc(54, sizeof(unsigned char));
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	int_as_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	int_as_char(bmpfileheader + 18, t->window_width);
	int_as_char(bmpfileheader + 22, t->window_height);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int get_color(t_cub3d *t, int x, int y)
{
	int	color;

	color = *(int*)(t->img_ptr + (4 * (int)t->window_width *
        ((int)t->window_height - 1 - y)) + (4 * x));
	return ((color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF));
}

static int write_data(int file, t_cub3d *t, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)t->window_height)
	{
		j = 0;
		while (j < (int)t->window_width)
		{
			color = get_color(t, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int save_bmp(t_cub3d *t)
{
	int			filesize;
	int			file;
	int			pad;

	pad = (4 - ((int)t->window_width * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)t->window_width + pad) * (int)t->window_height);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!write_header(file, filesize, t))
		return (0);
	if (!write_data(file, t, pad))
		return (0);
	close(file);
	return (1);
}