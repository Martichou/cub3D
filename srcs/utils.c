/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:32:01 by marandre          #+#    #+#             */
/*   Updated: 2019/12/09 13:17:16 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		exit_program(t_cub3d *t)
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
	if (t->mlx && t->win)
	{
		mlx_clear_window(t->mlx, t->win);
		mlx_destroy_window(t->mlx, t->win);
	}
	free(t);
	t = NULL;
	system("killall afplay 2&>/dev/null >/dev/null");
	exit(1);
	return (0);
}

int		error_printf(t_cub3d *t)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	if (t)
		exit_program(t);
	return (0);
}

// Need refactoring
void sort_sprites(int* order, double* dist, int amount)
{
	int gap;
	int swapped;

	gap = amount;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if(gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		for (int i = 0; i < amount - gap; i++)
		{
			int j = i + gap;
			if (dist[i] < dist[j])
			{
				swap_double(&dist[i], &dist[j]);
				swap_int(&order[i], &order[j]);
				swapped = 1;
			}
		}
	}
}
