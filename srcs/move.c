/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:43:04 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:25:01 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static void	check_goal(t_cub3d *t)
// {
// 	if (t->map[(int)t->player->x_pos][(int)t->player->y_pos] == 2)
// 	{
// 		t->player->chest_collected++;
// 		if (t->player->chest_collected == t->player->chest_to_collect)
// 			t->player->ended = 1;
// 		t->map[(int)t->player->x_pos][(int)t->player->y_pos] = 0;
// 	}
// }

static void	look(t_cub3d *t)
{
	if (t->key.look_right == 1)
	{
		t->x_olddir = t->player->x_dir;
		t->player->x_dir = t->player->x_dir * cos(-RS) - t->player->y_dir * sin(-RS);
		t->player->y_dir = t->x_olddir * sin(-RS) + t->player->y_dir * cos(-RS);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(-RS) - t->y_plane * sin(-RS);
		t->y_plane = t->x_oldplane * sin(-RS) + t->y_plane * cos(-RS);
	}
	if (t->key.look_left == 1)
	{
		t->x_olddir = t->player->x_dir;
		t->player->x_dir = t->player->x_dir * cos(RS) - t->player->y_dir * sin(RS);
		t->player->y_dir = t->x_olddir * sin(RS) + t->player->y_dir * cos(RS);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(RS) - t->y_plane * sin(RS);
		t->y_plane = t->x_oldplane * sin(RS) + t->y_plane * cos(RS);
	}
}

static void	move_lr(t_cub3d *t)
{
	if (t->key.move_right == 1)
	{
		if (t->map[(int)(t->player->x_pos + t->player->y_dir * MS + ((t->player->y_dir < 0) ? -OFFSET : OFFSET))][(int)(t->player->y_pos)] != 1)
			t->player->x_pos += t->player->y_dir * MS;
		if (t->map[(int)(t->player->x_pos)][(int)(t->player->y_pos - t->player->x_dir * MS - ((t->player->x_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->player->y_pos -= t->player->x_dir * MS;
	}
	if (t->key.move_left == 1)
	{
		if (t->map[(int)(t->player->x_pos - t->player->y_dir * MS - ((t->player->y_dir < 0) ? -OFFSET : OFFSET))][(int)(t->player->y_pos)] != 1)
			t->player->x_pos -= t->player->y_dir * MS;
		if (t->map[(int)(t->player->x_pos)][(int)(t->player->y_pos + t->player->x_dir * MS + ((t->player->x_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->player->y_pos += t->player->x_dir * MS;
	}
}

static void	move_ud(t_cub3d *t)
{
	if (t->key.move_up == 1)
	{
		if (t->map[(int)(t->player->x_pos + t->player->x_dir * MS + ((t->player->x_dir < 0) ? -OFFSET : OFFSET))][(int)(t->player->y_pos)] != 1)
			t->player->x_pos += t->player->x_dir * MS;
		if (t->map[(int)(t->player->x_pos)][(int)(t->player->y_pos + t->player->y_dir * MS + ((t->player->y_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->player->y_pos += t->player->y_dir * MS;
	}
	if (t->key.move_down == 1)
	{
		if (t->map[(int)(t->player->x_pos - t->player->x_dir * MS - ((t->player->x_dir < 0) ? -OFFSET : OFFSET))][(int)(t->player->y_pos)] != 1)
			t->player->x_pos -= t->player->x_dir * MS;
		if (t->map[(int)(t->player->x_pos)][(int)(t->player->y_pos - t->player->y_dir * MS - ((t->player->y_dir < 0) ? -OFFSET : OFFSET))] != 1)
			t->player->y_pos -= t->player->y_dir * MS;
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
