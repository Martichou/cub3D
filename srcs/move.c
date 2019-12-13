/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:43:04 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:17:39 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static void	check_goal(t_cub3d *t)
// {
// 	if (t->map[(int)t->x_pos][(int)t->y_pos] == 2)
// 	{
// 		t->player->chest_collected++;
// 		if (t->player->chest_collected == t->player->chest_to_collect)
// 			t->player->ended = 1;
// 		t->map[(int)t->x_pos][(int)t->y_pos] = 0;
// 	}
// }

static void	look(t_cub3d *t)
{
	if (t->look_right == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(-RS) - t->y_dir * sin(-RS);
		t->y_dir = t->x_olddir * sin(-RS) + t->y_dir * cos(-RS);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(-RS) - t->y_plane * sin(-RS);
		t->y_plane = t->x_oldplane * sin(-RS) + t->y_plane * cos(-RS);
	}
	if (t->look_left == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(RS) - t->y_dir * sin(RS);
		t->y_dir = t->x_olddir * sin(RS) + t->y_dir * cos(RS);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(RS) - t->y_plane * sin(RS);
		t->y_plane = t->x_oldplane * sin(RS) + t->y_plane * cos(RS);
	}
}

static void	move_lr(t_cub3d *t)
{
	if (t->move_right == 1)
	{
		if (t->map[(int)(t->x_pos + t->y_dir * MS + ((t->y_dir < 0) ? -OFFSET : OFFSET))][(int)(t->y_pos)] != 1)
			t->x_pos += t->y_dir * MS;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->x_dir * MS - ((t->x_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->y_pos -= t->x_dir * MS;
	}
	if (t->move_left == 1)
	{
		if (t->map[(int)(t->x_pos - t->y_dir * MS - ((t->y_dir < 0) ? -OFFSET : OFFSET))][(int)(t->y_pos)] != 1)
			t->x_pos -= t->y_dir * MS;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos + t->x_dir * MS + ((t->x_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->y_pos += t->x_dir * MS;
	}
}

static void	move_ud(t_cub3d *t)
{
	if (t->move_up == 1)
	{
		if (t->map[(int)(t->x_pos + t->x_dir * MS + ((t->x_dir < 0) ? -OFFSET : OFFSET))][(int)(t->y_pos)] != 1)
			t->x_pos += t->x_dir * MS;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos + t->y_dir * MS + ((t->y_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->y_pos += t->y_dir * MS;
	}
	if (t->move_down == 1)
	{
		if (t->map[(int)(t->x_pos - t->x_dir * MS - ((t->x_dir < 0) ? -OFFSET : OFFSET))][(int)(t->y_pos)] != 1)
			t->x_pos -= t->x_dir * MS;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->y_dir * MS - ((t->y_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->y_pos -= t->y_dir * MS;
	}
}

int			move(t_cub3d *t)
{
	if (t->multi.address)
		socket_frame(t);
	move_ud(t);
	move_lr(t);
	if (t->multi.address)
		send_movement(t, 0);
	look(t);
	//check_goal(t);
	ray(t);
	draw_gun(t);
	fps(t);
	return (0);
}
