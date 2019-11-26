/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:52:33 by marandre          #+#    #+#             */
/*   Updated: 2019/11/25 20:54:59 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_floor_color(t_cub3d *t, char *line)
{
	line++;
	if ((t->floor_color.rgb.r = ft_atoi(line)) > 255)
		return (0);
	line = ft_strchr(line, ',') + 1;
	if ((t->floor_color.rgb.g = ft_atoi(line)) > 255)
		return (0);
	line = ft_strchr(line, ',') + 1;
	if ((t->floor_color.rgb.b = ft_atoi(line)) > 255)
		return (0);
	return (1);
}

int	parse_ceilling_color(t_cub3d *t, char *line)
{
	line++;
	if ((t->ceilling_color.rgb.r = ft_atoi(line)) > 255)
		return (0);
	line = ft_strchr(line, ',') + 1;
	if ((t->ceilling_color.rgb.g = ft_atoi(line)) > 255)
		return (0);
	line = ft_strchr(line, ',') + 1;
	if ((t->ceilling_color.rgb.b = ft_atoi(line)) > 255)
		return (0);
	return (1);
}