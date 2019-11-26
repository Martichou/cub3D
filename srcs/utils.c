/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:32:01 by marandre          #+#    #+#             */
/*   Updated: 2019/11/26 14:26:10 by marandre         ###   ########.fr       */
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