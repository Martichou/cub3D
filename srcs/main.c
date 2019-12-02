/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:49 by marandre          #+#    #+#             */
/*   Updated: 2019/12/03 00:00:25 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int		cub3d(t_cub3d *t)
{
	t->ms = 0.05;
	t->rs = 0.05;
	t->lenline = -1;
	t->shooting = 0;
	t->fr = 17;
	t->life = 100;
	t->bullets = 8;
	t->reload = 0;
	if (!t->is_save)
		t->is_save = 0;
	if (!(t->zbuffer = malloc(sizeof(double) * t->window_width)))
		return (0);
	return (1);
}

static int mouse_hook(t_cub3d *t)
{
	(void)t;
	return (0);
}

int				main(int ac, char **av)
{
	t_cub3d *t;
	(void)av;
	if (ac < 2)
		return (error_printf());
	if (!(t = ft_calloc(sizeof(t_cub3d), 1)))
		return (error_printf());
	if (ft_strchr_at_end(av[1], ".cub") == -1)
		return (error_printf());
	if (ac > 2)
	{
		if (ft_strncmp(av[2], "--save", ft_strlen(av[2])) == 0)
		{
			t->name = av[0];
			t->is_save = 1;
			printf("Saving image\n");
		}
		else
			t->name = av[2];
	}
	else
		t->name = av[0];	
	t->mlx = mlx_init();
	t->sprites_number = 0;
	if (!(parse(t, av[1])))
		return (error_printf());
	t->win = mlx_new_window(t->mlx, t->window_width, t->window_height, TITLE);
	mlx_hook(t->win, 17, 0L, exit_program, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	mlx_hook(t->win, 17L, 0, exit_program, t);
	mlx_mouse_hook(t->win, mouse_hook, t);
	if (!cub3d(t))
		return (error_printf());
	ray(t);
	//system("afplay ./sounds/sound.mp3& 2&>/dev/null >/dev/null");
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
	return (0);
}