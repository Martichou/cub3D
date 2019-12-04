/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:44:41 by marandre          #+#    #+#             */
/*   Updated: 2019/12/04 16:58:19 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		key_press(int keycode, t_cub3d *t)
{
	if (keycode == 13)
		t->move_up = 1;
	else if (keycode == 1)
		t->move_down = 1;
	else if (keycode == 2)
		t->move_right = 1;
	else if (keycode == 0)
		t->move_left = 1;
	else if (keycode == 124)
		t->look_right = 1;
	else if (keycode == 123)
		t->look_left = 1;
	else if (keycode == 53)
		exit_program(t);
	else if (keycode == 17)
		t->texture = (t->texture == 1) ? 0 : 1;
	else if (keycode == 49)
		t->player->shooting = 1;
	return (0);
}

int		key_release(int keycode, t_cub3d *t)
{
	if (keycode == 13)
		t->move_up = 0;
	else if (keycode == 1)
		t->move_down = 0;
	else if (keycode == 2)
		t->move_right = 0;
	else if (keycode == 0)
		t->move_left = 0;
	else if (keycode == 124)
		t->look_right = 0;
	else if (keycode == 123)
		t->look_left = 0;
	return (0);
}