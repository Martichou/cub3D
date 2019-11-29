/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:32:01 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 15:15:54 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		exit_program(t_cub3d *t)
{
	int i = 0;
	while (i < t->nb_lines)
		free(t->map[i++]);
	free(t->map);
	t->map = NULL;
	system("killall afplay 2&>/dev/null >/dev/null");
	mlx_clear_window(t->mlx, t->win);
	mlx_destroy_window(t->mlx, t->win);
	free(t);
	exit(1);
	return (0);
}

int		error_printf()
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	return (0);
}

void sort_sprites(int* order, double* dist, int amount)
{
	int gap;
	int swapped;

	gap = amount;
	swapped = 0;
	while(gap > 1 || swapped)
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