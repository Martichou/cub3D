/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:26:49 by marandre          #+#    #+#             */
/*   Updated: 2019/11/25 22:19:45 by marandre         ###   ########.fr       */
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
}

int				main(int ac, char **av)
{
	t_cub3d *t;
	(void)av;
	if (ac != 2)
		return (ep);
	if (!(t = ft_calloc(sizeof(t_cub3d), 1)))
		return (ep);
	t->mlx = mlx_init();
	if (!(parse(t, av[1])))
		return (ep);

	printf("R %d %d\n", t->window_width, t->window_height);
	printf("F %d,%d,%d\n", t->floor_color.rgb.r, t->floor_color.rgb.g, t->floor_color.rgb.b);
	printf("C %d,%d,%d\n\n", t->ceilling_color.rgb.r, t->ceilling_color.rgb.g, t->ceilling_color.rgb.b);

	int i = 0;
	printf("Line height is %d\n", t->nb_lines);
	printf("Line len is %d\n", t->lenline);
	while (i < t->nb_lines)
	{
		int j = 0;
		while (j < t->lenline)
		{
			printf("%d", t->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	t->win = mlx_new_window(t->mlx, t->window_width, t->window_height, TITLE);
	mlx_hook(t->win, 17, 0L, exit_program, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	cub3d(t);
	ray(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
	return (0);
}