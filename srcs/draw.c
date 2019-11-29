/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:51:23 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 16:10:12 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	put_pxl_to_img(t_cub3d *t, int x, int y, int color)
{
	if (t->texture == 1 && x < t->window_width && y < t->window_height)
	{
		t->y_text = abs((((y * 256 - t->window_height * 128 +
			t->lineheight * 128) * 64) / t->lineheight) / 256);
		ft_memcpy(t->img_ptr + 4 * t->window_width * y + x * 4,
				&t->tex[t->id].data[t->y_text % 64 * t->tex[t->id].sizeline +
				t->x_text % 64 * t->tex[t->id].bpp / 8], sizeof(int));
	}
	else if (x < t->window_width && y < t->window_height)
		ft_memcpy(t->img_ptr + 4 * t->window_width * y + x * 4, &color, sizeof(int));
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
		put_pxl_to_img(t, x, start,
			ft_add_ao(t->color, ((start - t->min) * 100. / (t->max - t->min))));
}

void	draw_sky(t_cub3d *t)
{
	t->x_text = 0;
	while (t->x_text < t->window_width)
	{
		t->y_text = 0;
		while (t->y_text < t->window_height / 2)
		{
			ft_memcpy(t->img_ptr + 4 * t->window_width * t->y_text + t->x_text * 4,
					&t->tex[4].data[t->y_text % 512 * t->tex[4].sizeline +
					t->x_text % 512 * t->tex[4].bpp / 8], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}

static void		animate_shotgun(t_cub3d *t, int posx, int posy)
{
	if (t->fr >= 15 && t->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[6].img, posx, posy);
	else if (t->fr >= 12 && t->fr <= 14 && t->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[7].img, posx, posy);
	else if (t->fr >= 10 && t->fr <= 11 && t->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[8].img, posx, posy);
	else if (t->fr >= 7 && t->fr <= 9 && t->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[9].img, posx, posy);
	else if (t->fr >= 5 && t->fr <= 7 && t->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[9].img, posx, posy);
	else if (t->fr >= 1 && t->fr <= 4 && t->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[7].img, posx, posy);
	t->fr--;
	if (t->fr == 1)
	{
		t->fr = 17;
		t->shooting = 0;
		if (t->reload == 1)
		{
			t->bullets = 8;
			t->reload = 0;
		}
	}
}

void	draw_gun(t_cub3d *t)
{
	int posx;
	int posy;

	posx = (t->window_width - 400) / 2;
	posy = t->window_height - 400;
	if (t->shooting == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[5].img, posx, posy);
	else
	{
		if (t->fr == 17 && (t->fr--))
		{
			if (t->bullets > 0)
			{
				t->bullets--;
				system("afplay ./sounds/shot.mp3& 2&>/dev/null >/dev/null");
			}
			else
				t->reload = 1;
		}
		animate_shotgun(t, posx, posy);
	}
}