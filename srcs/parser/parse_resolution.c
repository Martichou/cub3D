/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:46:38 by marandre          #+#    #+#             */
/*   Updated: 2019/12/09 17:30:30 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		parse_resolution(t_cub3d *t, char *line)
{
	t->window_width = ft_atoi(line);
	line = ft_strrchr(line, ' ') + 1;
	t->window_height = ft_atoi(line);
	if (t->window_width > 1920)
		t->window_width = 1920;
	if (t->window_height > 1080)
		t->window_height = 1080;
	if (t->window_width < 848)
		t->window_width = 848;
	if (t->window_height < 480)
		t->window_height = 480;
	return (1);
}