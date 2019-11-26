/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:43:04 by marandre          #+#    #+#             */
/*   Updated: 2019/11/26 22:58:59 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		move(t_cub3d *t)
{
	if (t->move_up == 1)
	{
		if (t->map[(int)(t->x_pos + t->x_dir * t->ms)][(int)(t->y_pos)] == 0)
			t->x_pos += t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos + t->y_dir * t->ms)] == 0)
			t->y_pos += t->y_dir * t->ms;
	}
	if (t->move_down == 1)
	{
		if (t->map[(int)(t->x_pos - t->x_dir * t->ms)][(int)(t->y_pos)] == 0)
			t->x_pos -= t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->y_dir * t->ms)] == 0)
			t->y_pos -= t->y_dir * t->ms;
	}
	if (t->move_right == 1)
	{
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->x_dir * t->ms)] == 0)
			t->y_pos -= t->x_dir * t->ms;
	}
	if (t->move_left == 1)
	{
		if (t->map[(int)(t->x_pos - t->x_dir * t->ms)][(int)(t->y_pos)] == 0)
			t->y_pos += t->x_dir * t->ms;
	}
	if (t->look_right == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(-t->rs) - t->y_dir * sin(-t->rs);
		t->y_dir = t->x_olddir * sin(-t->rs) + t->y_dir * cos(-t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(-t->rs) - t->y_plane * sin(-t->rs);
		t->y_plane = t->x_oldplane * sin(-t->rs) + t->y_plane * cos(-t->rs);
	}
	if (t->look_left == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(t->rs) - t->y_dir * sin(t->rs);
		t->y_dir = t->x_olddir * sin(t->rs) + t->y_dir * cos(t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(t->rs) - t->y_plane * sin(t->rs);
		t->y_plane = t->x_oldplane * sin(t->rs) + t->y_plane * cos(t->rs);
	}
	ray(t);
	draw_gun(t);
	return (0);
}