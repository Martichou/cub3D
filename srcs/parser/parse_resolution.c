/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:46:38 by marandre          #+#    #+#             */
/*   Updated: 2019/11/25 20:47:52 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		parse_resolution(t_cub3d *t, char *line)
{
	t->window_width = ft_atoi(line);
	line = ft_strrchr(line, ' ') + 1;
	t->window_height = ft_atoi(line);
	return (1);
}