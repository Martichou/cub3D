/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:42:06 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:34:27 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	put_hud(t_cub3d *t)
{
	int	i;

	i = 0;
	while (i++ < t->player->life)
		mlx_string_put(t->window.mlx, t->window.win, 10 + i,
			t->window.window_height - 10, 0xFF0000, "|");
	while (i++ < 100)
		mlx_string_put(t->window.mlx, t->window.win, 10 + i,
			t->window.window_height - 10, 0x808080, "|");
	// mlx_string_put(t->window.mlx, t->win, 15,
	// 	t->window.window_height - 30, 0xffffff, "Collected   / ");
	// mlx_string_put(t->window.mlx, t->win, 90,
	// 	t->window.window_height - 30, 0xffffff, ft_itoa(t->player->chest_collected));
	// mlx_string_put(t->window.mlx, t->win, 108,
	// 	t->window.window_height - 30, 0xffffff, ft_itoa(t->player->chest_to_collect));
	mlx_string_put(t->window.mlx, t->window.win, t->window.window_width - 30,
		t->window.window_height - 10, 0xffffff, ft_itoa(t->player->bullets));
	mlx_string_put(t->window.mlx, t->window.win,
		t->window.window_width - 30, t->window.window_height - 10, 0xffffff, " /8");
	mlx_string_put(t->window.mlx, t->window.win,
		t->window.window_width / 2, t->window.window_height / 2 + 15, 0xffffff, ".");
}

void		fps(t_cub3d *t)
{
	static int		timestamp;
	static int		fps;
	static int		fps_temp;

	if (time(NULL) != timestamp)
	{
		fps_temp = fps;
		fps = 0;
		timestamp = (int)time(NULL);
	}
	else
		fps++;
	mlx_string_put(t->window.mlx, t->window.win, 10, 20, 0xffffff, t->player->name);
	mlx_string_put(t->window.mlx, t->window.win, t->window.window_width - 20,
		20, 0xe5e500, ft_itoa(fps_temp + 1));
	put_hud(t);
}
