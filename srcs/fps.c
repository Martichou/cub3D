/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:42:06 by marandre          #+#    #+#             */
/*   Updated: 2019/11/28 15:20:18 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	fps(t_cub3d *t)
{
	static int		timestamp;
	static int		fps;
	static int		fps_2;

	if (time(NULL) != timestamp)
	{
		fps_2 = fps;
		fps = 0;
		timestamp = (int)time(NULL);
	}
	else
		fps++;
	mlx_string_put(t->mlx, t->win, 10, 15, 0xFFFFFF, "FPS  :");
	mlx_string_put(t->mlx, t->win, 70, 15, 0xFFFFFF, ft_itoa(fps_2));
	mlx_string_put(t->mlx, t->win, 10, 30, 0xFF0000, "LIFE  :");
	mlx_string_put(t->mlx, t->win, 70, 30, 0xFF0000, ft_itoa(t->life));
}