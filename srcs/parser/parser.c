/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:36:16 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 17:55:23 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static t_option_parser	option_parsers[] =
{
	{"R", parse_resolution, 1},
	{"NO", parse_north_texture, 2},
	{"SO", parse_south_texture, 2},
	{"WE", parse_west_texture, 2},
	{"EA", parse_east_texture, 2},
	{"S", parse_sprite_texture_10, 1},
	{"X", parse_sprite_texture_11, 1},
	{"F", parse_floor_color, 1},
	{"C", parse_ceilling_color, 1},
	{"1", parse_map, 0}
};

#define OPTIONS_PARSERS_SIZE (sizeof(option_parsers) / sizeof(t_option_parser))

static int parse_line(t_cub3d *t, char *line)
{
	int i;

	if (!*line)
		return (1);
	i = -1;
	while (++i < (int)OPTIONS_PARSERS_SIZE)
		if (ft_strncmp(option_parsers[i].id, line, ft_strlen(option_parsers[i].id)) == 0)
			return (option_parsers[i].func(t, line + option_parsers[i].to_skip));
	return (0);
}

static int	count_sprites(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line == '2' || *line == '3')
			i++;
		++line;
	}
	return (i);
}

static int	setup_map(t_cub3d *t, char *filename)
{
	int		fd;
	int		ret;
	char	*line;
	
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (*line == '1')
		{
			t->sprites_number += count_sprites(line);
			t->nb_lines++;
		}
		free(line);
	}
	close(fd);
	if (ret == -1)
		return (0);
	if (!(t->map = (int **)malloc(sizeof(int *) * t->nb_lines))
		|| !(t->sprites = malloc(sizeof(t_sprites) * t->sprites_number)))
		return (0);
	return(1);
}

int     parse(t_cub3d *t, char *filename)
{
	int		fd;
	int		ret;
	char	*line;

	t->map = NULL;
	t->ceilling_color.hexcode = 0;
	t->floor_color.hexcode = 0;
	if (!setup_map(t, filename))
		return (0);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!parse_line(t, line))
			return (0);
		free(line);
	}
	close(fd);
	if (ret == -1)
		return (0);
	setup_sky(t);
	setup_shotgun(t);
	return (1);
}