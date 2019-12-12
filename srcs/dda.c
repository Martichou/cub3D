/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:26:54 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 00:26:43 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void		dda_init(t_cub3d *t)
{
	t->x_deltadist = sqrt(1 + (t->y_raydir * t->y_raydir)
			/ (t->x_raydir * t->x_raydir));
	t->y_deltadist = sqrt(1 + (t->x_raydir * t->x_raydir)
			/ (t->y_raydir * t->y_raydir));
	if (t->x_raydir < 0 && (t->x_step = -1))
		t->x_sidedist = (t->x_raypos - t->x_map) * t->x_deltadist;
	else if ((t->x_step = 1))
		t->x_sidedist = (t->x_map + 1.0 - t->x_raypos) * t->x_deltadist;
	if (t->y_raydir < 0 && (t->y_step = -1))
		t->y_sidedist = (t->y_raypos - t->y_map) * t->y_deltadist;
	else if ((t->y_step = 1))
		t->y_sidedist = (t->y_map + 1.0 - t->y_raypos) * t->y_deltadist;
}

void		dda(t_cub3d *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->x_sidedist < t->y_sidedist)
		{
			t->x_sidedist += t->x_deltadist;
			t->x_map += t->x_step;
			t->side = (t->x_pos > t->x_map) ? 0 : 1;
			t->color = (t->side == 0) ? WALL_N : WALL_S;
		}
		else
		{
			t->y_sidedist += t->y_deltadist;
			t->y_map += t->y_step;
			t->side = (t->y_pos > t->y_map) ? 2 : 3;
			t->color = (t->side == 2) ? WALL_W : WALL_E;
		}
		if (t->map[t->x_map][t->y_map] == 1)
			t->hit = 1;
	}
}
