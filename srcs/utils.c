/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:32:01 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:29:54 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			exit_program(t_cub3d *t)
{
	int i;

	i = 0;
	while (i < t->nb_lines)
		free(t->map[i++]);
	free(t->map);
	t->map = NULL;
	free(t->sprites);
	t->sprites = NULL;
	free(t->zbuffer);
	t->zbuffer = NULL;
	free(t->player);
	t->player = NULL;
	if (t->window.mlx && t->window.win)
	{
		mlx_clear_window(t->window.mlx, t->window.win);
		mlx_destroy_window(t->window.mlx, t->window.win);
	}
	free(t);
	t = NULL;
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(1);
	return (0);
}

int			error_printf(t_cub3d *t)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	if (t)
		exit_program(t);
	return (0);
}

void		sort_sprites(int *order, double *dist, int amount)
{
	int gap;
	int swapped;
	int j;
	int i;

	gap = amount;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		i = -1;
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		gap = (gap < 1) ? 1 : gap;
		while (++i < amount - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				swap_double(&dist[i], &dist[j]);
				swap_int(&order[i], &order[j]);
				return ;
			}
		}
	}
}
