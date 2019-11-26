/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:49 by marandre          #+#    #+#             */
/*   Updated: 2019/11/26 16:18:25 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		cub3d(t_cub3d *t)
{
	t->x_dir = -1;
	t->y_plane = 0.66;
	t->ms = 0.05;
	t->rs = 0.05;
	t->lenline = -1;
	t->shooting = 0;
	t->fr = 17;
}

int				main(int ac, char **av)
{
	t_cub3d *t;
	(void)av;
	if (ac != 2)
		return (error_printf());
	if (!(t = ft_calloc(sizeof(t_cub3d), 1)))
		return (error_printf());
	if (ft_strchr_at_end(av[1], ".cub") == -1)
		return (error_printf());
	t->mlx = mlx_init();
	if (!(parse(t, av[1])))
		return (error_printf());
	t->win = mlx_new_window(t->mlx, t->window_width, t->window_height, TITLE);
	mlx_hook(t->win, 17, 0L, exit_program, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	cub3d(t);
	ray(t);
	//system("afplay ./sounds/sound.mp3& 2&>/dev/null >/dev/null");
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
	return (0);
}