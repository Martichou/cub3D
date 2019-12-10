/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:49 by marandre          #+#    #+#             */
/*   Updated: 2019/12/10 15:32:31 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int		cub3d(t_cub3d *t)
{
	t->texture = 1;
	t->lenline = -1;
	t->player->shooting = 0;
	t->player->fr = 17;
	t->player->life = 100;
	t->player->bullets = 8;
	t->player->reload = 0;
	t->x_pos += 0.5;
	t->y_pos += 0.5;
	if (!t->is_save)
		t->is_save = 0;
	if (!(t->zbuffer = malloc(sizeof(double) * t->window_width)))
		return (0);
	return (1);
}

static int		mouse_hook(t_cub3d *t)
{
	(void)t;
	return (0);
}

static int		check_val(t_cub3d *t)
{
	if (t->window_width == 0 || t->window_height == 0)
		return (0);
	if (t->x_pos == 0 || t->y_pos == 0)
		return (0);
	if (!t->tex[0].img || !t->tex[1].img || !t->tex[2].img || !t->tex[3].img
		|| !t->tex[4].img || !t->tex[5].img || !t->tex[6].img || !t->tex[7].img
		|| !t->tex[8].img || !t->tex[9].img)
		return (0);
	if (t->sprites_number > 0 && (!t->tex[10].img))
		return (0);
	return (1);
}

static void		check_name_save(int ac, char **av, t_cub3d *t)
{
	if (ac > 2)
	{
		if (ft_strncmp(av[2], "--save", ft_strlen(av[2])) == 0)
		{
			t->player->name = av[0];
			t->is_save = 1;
		}
		else
			t->player->name = av[2];
	}
	else
		t->player->name = av[0];
}

int				main(int ac, char **av)
{
	t_cub3d *t;

	if (ac < 2)
		return (error_printf(NULL));
	if (!(t = ft_calloc(sizeof(t_cub3d), 1))
		|| (!(t->player = ft_calloc(sizeof(t_player), 1)))
		|| ft_strchr_at_end(av[1], ".cub") == -1)
		return (error_printf(t));
	check_name_save(ac, av, t);
	t->mlx = mlx_init();
	if (!(parse(t, av[1])))
		return (error_printf(t));
	if (!check_val(t))
		return (error_printf(t));
	t->win = mlx_new_window(t->mlx, t->window_width, t->window_height, TITLE);
	mlx_hook(t->win, 17, 0L, exit_program, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	mlx_hook(t->win, 17L, 0, exit_program, t);
	mlx_mouse_hook(t->win, mouse_hook, t);
	if (!cub3d(t))
		return (error_printf(t));
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
	return (0);
}
