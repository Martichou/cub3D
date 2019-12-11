/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:47:52 by marandre          #+#    #+#             */
/*   Updated: 2019/12/11 21:07:02 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		ray_casting_init(t_cub3d *t, int x)
{
	t->x_cam = 2 * x / (double)(t->window_width) - 1;
	t->x_raypos = t->x_pos;
	t->y_raypos = t->y_pos;
	t->x_raydir = t->x_dir + t->x_plane * t->x_cam;
	t->y_raydir = t->y_dir + t->y_plane * t->x_cam;
	t->x_map = (int)t->x_raypos;
	t->y_map = (int)t->y_raypos;
	dda_init(t);
	dda(t);
	if (t->side == 0 || t->side == 1)
		t->walldist = (t->x_map - t->x_raypos +
				(1 - t->x_step) / 2) / t->x_raydir;
	else
		t->walldist = (t->y_map - t->y_raypos +
				(1 - t->y_step) / 2) / t->y_raydir;
}

static void		floor_and_ceiling(t_cub3d *t, int x)
{
	if (t->texture == 0)
	{
		if (t->start > 0)
		{
			t->color = t->ceilling_color.hexcode;
			t->y = -1;
			if (x < t->window_width && t->y < t->window_height)
				while (++t->y < t->start)
					ft_memcpy(t->img_ptr + 4 * t->window_width *
						t->y + x * 4, &t->color, sizeof(int));
		}
	}
	if (t->end > 0)
	{
		t->color = t->floor_color.hexcode;
		t->y = t->end - 1;
		if (x < t->window_width && t->y < t->window_height)
			while (++t->y < t->window_height)
				ft_memcpy(t->img_ptr + 4 * t->window_width *
					t->y + x * 4, &t->color, sizeof(int));
	}
}

static void		sprites_and_put(t_cub3d *t)
{
	if (!draw_sprites(t))
		error_printf(t);
	if (t->other && !draw_player(t))
		error_printf(t);
	if (t->is_save)
	{
		save_bmp(t);
		exit_program(t);
	}
	else
		mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
}

void			ray(t_cub3d *t)
{
	t->x = -1;
	t->img = mlx_new_image(t->mlx, t->window_width, t->window_height);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
	if (t->texture == 1)
		draw_sky(t);
	while (++t->x < t->window_width)
	{
		ray_casting_init(t, t->x);
		t->lineheight = (int)(t->window_height / t->walldist);
		t->start = -t->lineheight / 2 + t->window_height / 2;
		if (t->start < 0)
			t->start = 0;
		t->end = t->lineheight / 2 + t->window_height / 2;
		if (t->end >= t->window_height)
			t->end = t->window_height - 1;
		t->min = ((t->window_height / 2) - t->lineheight);
		t->max = ((t->window_height / 2) + t->lineheight);
		t->zbuffer[t->x] = t->walldist;
		draw_wall(t->x, t->start - 1, t->end, t);
		floor_and_ceiling(t, t->x);
	}
	sprites_and_put(t);
}
