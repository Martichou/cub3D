/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:44:41 by marandre          #+#    #+#             */
/*   Updated: 2019/11/25 12:15:58 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		key_press(int keycode, t_cub3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->move_up = 1;
	else if (keycode == 1 || keycode == 125)
		t->move_down = 1;
	else if (keycode == 2 || keycode == 124)
		t->move_right = 1;
	else if (keycode == 0 || keycode == 123)
		t->move_left = 1;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.1;
	else if (keycode == 53)
		exit_program(t);
	else if (keycode == 17)
		t->texture = (t->texture == 1) ? 0 : 1;
	return (0);
}

int		key_release(int keycode, t_cub3d *t)
{
	if (keycode == 13 || keycode == 126)
		t->move_up = 0;
	else if (keycode == 1 || keycode == 125)
		t->move_down = 0;
	else if (keycode == 2 || keycode == 124)
		t->move_right = 0;
	else if (keycode == 0 || keycode == 123)
		t->move_left = 0;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.05;
	return (0);
}