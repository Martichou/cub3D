/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:43:04 by marandre          #+#    #+#             */
/*   Updated: 2019/12/03 17:56:27 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	check_goal(t_cub3d *t)
{
	if (t->map[(int)t->x_pos][(int)t->y_pos] == 2)
	{
		t->player->chest_collected++;
		if (t->player->chest_collected == t->player->chest_to_collect)
			t->player->ended = 1;
		t->map[(int)t->x_pos][(int)t->y_pos] = 0;
		// Maybe change texture of the chest to an open chest
		// Pass spritesOrder as global and spritesDistances
		// Then the closest sprites is the sprites we're on
		// We can check that by comparing the x and y value
	}
}

static void	look(t_cub3d *t)
{
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
}

static void	move_lr(t_cub3d *t)
{
	if (t->move_right == 1)
	{
		if (t->map[(int)(t->x_pos + t->y_dir * t->ms)][(int)(t->y_pos)] != 1)
			t->x_pos += t->y_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->x_dir * t->ms)] != 1)
			t->y_pos -= t->x_dir * t->ms;
	}
	if (t->move_left == 1)
	{
		if (t->map[(int)(t->x_pos - t->y_dir * t->ms)][(int)(t->y_pos)] != 1)
			t->x_pos -= t->y_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos + t->x_dir * t->ms)] != 1)
			t->y_pos += t->x_dir * t->ms;
	}
}

static void	move_ud(t_cub3d *t)
{
	if (t->move_up == 1)
	{
		if (t->map[(int)(t->x_pos + t->x_dir * t->ms)][(int)(t->y_pos)] != 1)
			t->x_pos += t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos + t->y_dir * t->ms)] != 1)
			t->y_pos += t->y_dir * t->ms;
	}
	if (t->move_down == 1)
	{
		if (t->map[(int)(t->x_pos - t->x_dir * t->ms)][(int)(t->y_pos)] != 1)
			t->x_pos -= t->x_dir * t->ms;
		if (t->map[(int)(t->x_pos)][(int)(t->y_pos - t->y_dir * t->ms)] != 1)
			t->y_pos -= t->y_dir * t->ms;
	}	
}

int		move(t_cub3d *t)
{
	move_ud(t);
	move_lr(t);
	look(t);
	check_goal(t);
	ray(t);
	draw_gun(t);
	fps(t);
	return (0);
}