/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:49 by marandre          #+#    #+#             */
/*   Updated: 2019/11/21 20:47:35 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void		init_mlx(t_cub3d *t)
{
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, WINX, WINY, TITLE);
}

static void		cub3d_load_textures(t_cub3d *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[0].img = mlx_xpm_file_to_image(t->mlx, "textures/wood.xpm", &a, &b);
	t->tex[0].data = mlx_get_data_addr(t->tex[0].img, &t->tex[0].bpp,
			&t->tex[0].sizeline, &t->tex[0].endian);
	t->tex[1].img = mlx_xpm_file_to_image(t->mlx, "textures/stone.xpm", &a, &b);
	t->tex[1].data = mlx_get_data_addr(t->tex[1].img, &t->tex[1].bpp,
			&t->tex[1].sizeline, &t->tex[1].endian);
	t->tex[2].img = mlx_xpm_file_to_image(t->mlx, "textures/mossy.xpm", &a, &b);
	t->tex[2].data = mlx_get_data_addr(t->tex[2].img, &t->tex[2].bpp,
			&t->tex[2].sizeline, &t->tex[2].endian);
	t->tex[3].img = mlx_xpm_file_to_image(t->mlx,
			"textures/redbrick.xpm", &a, &b);
	t->tex[3].data = mlx_get_data_addr(t->tex[3].img, &t->tex[3].bpp,
			&t->tex[3].sizeline, &t->tex[3].endian);
	t->tex[4].img = mlx_xpm_file_to_image(t->mlx, "textures/wood.xpm", &a, &b);
	t->tex[4].data = mlx_get_data_addr(t->tex[4].img, &t->tex[4].bpp,
			&t->tex[4].sizeline, &t->tex[4].endian);
	t->tex[5].img = mlx_xpm_file_to_image(t->mlx, "textures/sand.xpm", &a, &b);
	t->tex[5].data = mlx_get_data_addr(t->tex[5].img, &t->tex[5].bpp,
			&t->tex[5].sizeline, &t->tex[5].endian);
	a = 512;
	b = 512;
	t->tex[6].img = mlx_xpm_file_to_image(t->mlx, "textures/sky.xpm", &a, &b);
	t->tex[6].data = mlx_get_data_addr(t->tex[6].img, &t->tex[6].bpp,
			&t->tex[6].sizeline, &t->tex[6].endian);
}

static void		cub3d(t_cub3d *t)
{
	t->x_pos = 3;
	t->y_pos = 3;
	t->x_dir = -1;
	t->y_dir = 0;
	t->x_plane = 0;
	t->y_plane = 0.66;
	t->ms = 0.05;
	t->rs = 0.05;
	t->move_up = 0;
	t->move_down = 0;
	t->move_left = 0;
	t->move_right = 0;
	t->x_text = 0;
	t->y_text = 0;
	cub3d_load_textures(t);
}

int				main(int ac, char **av)
{
	t_cub3d *t;
	(void)av;
	if (ac != 2)
		return (ep);
	if (!(t = malloc(sizeof(t_cub3d))))
		return (ep);
	if (!(parsing(t, av[1])))
		return (ep);
	init_mlx(t);
	mlx_hook(t->win, 17, 0L, exit_program, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	cub3d(t);
	ray(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
	return (0);
}