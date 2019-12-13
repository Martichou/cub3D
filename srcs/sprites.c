/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:28:24 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:35:02 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_struct(t_sprites_work *spw, t_cub3d *t,
	int *so, int i)
{
	spw->sp_x = t->sprites[so[i]].x + 0.5 - t->player->x_pos;
	spw->sp_y = t->sprites[so[i]].y + 0.5 - t->player->y_pos;
	spw->inv_det = 1.0 / (t->x_plane * t->player->y_dir - t->player->x_dir * t->y_plane);
	spw->transform_x = spw->inv_det *
		(t->player->y_dir * spw->sp_x - t->player->x_dir * spw->sp_y);
	spw->transform_y = spw->inv_det *
		(-t->y_plane * spw->sp_x + t->x_plane * spw->sp_y);
	spw->sp_screen_x = (int)((t->window.window_width / 2) *
		(1 + spw->transform_x / spw->transform_y));
	spw->vms = (int)(VMOVE / spw->transform_y);
	spw->sp_height = abs((int)(t->window.window_height / (spw->transform_y))) / VDIV;
	spw->draw_start_y = -spw->sp_height / 2 +
		t->window.window_height / 2 + spw->vms;
	if (spw->draw_start_y < 0)
		spw->draw_start_y = 0;
	spw->draw_end_y = spw->sp_height / 2 + t->window.window_height / 2 + spw->vms;
	if (spw->draw_end_y >= t->window.window_height)
		spw->draw_end_y = t->window.window_height - 1;
	spw->sp_width = abs((int)(t->window.window_height / (spw->transform_y))) / UDIV;
	spw->draw_start_x = -spw->sp_width / 2 + spw->sp_screen_x;
	if (spw->draw_start_x < 0)
		spw->draw_start_x = 0;
	spw->draw_end_x = spw->sp_width / 2 + spw->sp_screen_x;
	if (spw->draw_end_x >= t->window.window_width)
		spw->draw_end_x = t->window.window_width - 1;
}

static void	print_sprites(t_cub3d *t, t_sprites_work *spw, int *so, int i)
{
	spw->tex_x = (int)(256 * (spw->stripe - (-spw->sp_width / 2 +
		spw->sp_screen_x)) * 64 / spw->sp_width) / 256;
	if (spw->transform_y > 0 && spw->stripe > 0 && spw->stripe <
		t->window.window_width && spw->transform_y < t->zbuffer[spw->stripe])
	{
		spw->y = spw->draw_start_y - 1;
		while (++spw->y < spw->draw_end_y)
		{
			spw->d = (spw->y - spw->vms) * 256 - t->window.window_height *
				128 + spw->sp_height * 128;
			spw->tex_y = ((spw->d * 64) / spw->sp_height) / 256;
			spw->color = t->tex[t->sprites[so[i]].tex_index].
				data[spw->tex_y % 64 * t->tex[t->sprites[so[i]].
				tex_index].sizeline + spw->tex_x % 64 *
				t->tex[t->sprites[so[i]].tex_index].bpp / 8];
			if ((spw->color & 0x00FFFFFF) != 0)
				ft_memcpy(t->window.img_ptr + 4 * t->window.window_width * spw->y +
					spw->stripe * 4, &t->tex[t->sprites[so[i]].tex_index].
					data[spw->tex_y % 64 * t->tex[t->sprites[so[i]].
					tex_index].sizeline + spw->tex_x % 64 *
					t->tex[t->sprites[so[i]].tex_index].bpp / 8], sizeof(int));
		}
	}
}

int			draw_sprites(t_cub3d *t)
{
	int				so[t->sprites_number];
	double			sd[t->sprites_number];
	t_sprites_work	*spw;
	int				i;

	i = -1;
	while (++i < t->sprites_number)
	{
		so[i] = i;
		sd[i] = ((t->player->x_pos - t->sprites[i].x) * (t->player->x_pos - t->sprites[i].x) +
			(t->player->y_pos - t->sprites[i].y) * (t->player->y_pos - t->sprites[i].y));
	}
	sort_sprites(so, sd, t->sprites_number);
	i = -1;
	if (!(spw = ft_calloc(sizeof(t_sprites_work), 1)))
		return (0);
	while (++i < t->sprites_number)
	{
		fill_struct(spw, t, so, i);
		spw->stripe = spw->draw_start_x - 1;
		while (++spw->stripe < spw->draw_end_x)
			print_sprites(t, spw, so, i);
	}
	free(spw);
	return (1);
}
