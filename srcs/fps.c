/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:42:06 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 17:59:13 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fps(t_cub3d *t)
{
	static int		timestamp;
	static int		fps;
	static int		fps_2;
	int i;

	i = 0;
	if (time(NULL) != timestamp)
	{
		fps_2 = fps;
		fps = 0;
		timestamp = (int)time(NULL);
	}
	else
		fps++;
	mlx_string_put(t->mlx, t->win, 10, 20, 0xffffff, t->name);
	mlx_string_put(t->mlx, t->win, t->window_width - 20, 20, 0xe5e500, ft_itoa(fps_2 + 1));
	while (i++ < t->life)
		mlx_string_put(t->mlx, t->win, 10 + i, t->window_height - 10, 0xFF0000, "|");
	while (i++ < 100)
		mlx_string_put(t->mlx, t->win, 10 + i, t->window_height - 10, 0x808080, "|");
	mlx_string_put(t->mlx, t->win, t->window_width - 30, t->window_height - 10, 0xffffff, ft_itoa(t->bullets));
	mlx_string_put(t->mlx, t->win, t->window_width - 30, t->window_height - 10, 0xffffff, " /8");
	mlx_string_put(t->mlx, t->win, t->window_width / 2, t->window_height / 2 + 15, 0xffffff, ".");
}