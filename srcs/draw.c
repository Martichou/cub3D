/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:51:23 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 00:25:18 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	put_pxl_to_img(t_cub3d *t, int x, int y)
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
		ft_memcpy(t->img_ptr + 4 * t->window_width * y + x * 4,
			&t->color, sizeof(int));
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
		put_pxl_to_img(t, x, start);
}

void		draw_sky(t_cub3d *t)
{
	t->x_text = 0;
	while (t->x_text < t->window_width)
	{
		t->y_text = 0;
		while (t->y_text < t->window_height / 2)
		{
			ft_memcpy(t->img_ptr + 4 * t->window_width * t->y_text +
					t->x_text * 4, &t->tex[4].data[t->y_text % 512 *
					t->tex[4].sizeline + t->x_text % 512 *
					t->tex[4].bpp / 8], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}

static void	animate_shotgun(t_cub3d *t, int posx, int posy)
{
	if (t->player->fr >= 15 && t->player->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[6].img, posx, posy);
	else if (t->player->fr >= 12 && t->player->fr <= 14
		&& t->player->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[7].img, posx, posy);
	else if (t->player->fr >= 10 && t->player->fr <= 11
		&& t->player->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[8].img, posx, posy);
	else if (t->player->fr >= 7 && t->player->fr <= 9 && t->player->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[9].img, posx, posy);
	else if (t->player->fr >= 5 && t->player->fr <= 7 && t->player->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[9].img, posx, posy);
	else if (t->player->fr >= 1 && t->player->fr <= 4 && t->player->reload == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[7].img, posx, posy);
	t->player->fr--;
	if (t->player->fr == 1)
	{
		t->player->fr = 17;
		t->player->shooting = 0;
		if (t->player->reload == 1)
		{
			t->player->bullets = 8;
			t->player->reload = 0;
		}
	}
}

void		draw_gun(t_cub3d *t)
{
	int posx;
	int posy;

	posx = (t->window_width - 400) / 2;
	posy = t->window_height - 400;
	if (t->player->shooting == 0)
		mlx_put_image_to_window(t->mlx, t->win, t->tex[5].img, posx, posy);
	else
	{
		if (t->player->fr == 17 && (t->player->fr--))
		{
			if (t->player->bullets > 0)
			{
				t->player->bullets--;
				system("afplay ./sounds/shot.mp3& 2&>/dev/null >/dev/null");
			}
			else
				t->player->reload = 1;
		}
		animate_shotgun(t, posx, posy);
	}
}
