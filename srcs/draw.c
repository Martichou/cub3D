/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:51:23 by marandre          #+#    #+#             */
/*   Updated: 2019/11/25 11:54:36 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	put_pxl_to_img(t_cub3d *t, int x, int y, int color)
{
	if (t->texture == 1 && x < WINX && y < WINY)
	{
		t->y_text = abs((((y * 256 - WINY * 128 + t->lineheight * 128) * 64)
					/ t->lineheight) / 256);
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4,
				&t->tex[t->id].data[t->y_text % 64 * t->tex[t->id].sizeline +
				t->x_text % 64 * t->tex[t->id].bpp / 8], sizeof(int));
	}
	else if (x < WINX && y < WINY)
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4, &color, sizeof(int));
}

void		draw_wall(int x, int start, int end, t_cub3d *t)
{
	if (t->texture == 1)
	{
		t->id = t->side;
		if (t->side == 0 || t->side == 1)
			t->x_wall = t->y_raypos + t->walldist * t->y_raydir;
		else
			t->x_wall = t->x_raypos + t->walldist * t->x_raydir;
		t->x_text = 64 - (int)(t->x_wall * (double)(64)) - 1;
		t->x_text = abs(t->x_text);
	}
	while (++start <= end)
		put_pxl_to_img(t, x, start, t->color);
}

void	draw_sky(t_cub3d *t)
{
	t->x_text = 0;
	while (t->x_text < WINX)
	{
		t->y_text = 0;
		while (t->y_text < WINY / 2)
		{
			ft_memcpy(t->img_ptr + 4 * WINX * t->y_text + t->x_text * 4,
					&t->tex[6].data[t->y_text % 512 * t->tex[6].sizeline +
					t->x_text % 512 * t->tex[6].bpp / 8], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}
