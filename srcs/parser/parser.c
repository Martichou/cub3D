/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:36:16 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:32:44 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static t_option_parser	g_opt_p[] =
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
	{"1", parse_map, 0},
	{"0", parse_map, 0}
};

#define OPTIONS_PARSERS_SIZE (sizeof(g_opt_p) / sizeof(t_option_parser))

static int				setup_shotgun(t_cub3d *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[5].img = mlx_xpm_file_to_image(t->window.mlx, "textures/gun.xpm", &a, &b);
	t->tex[5].data = mlx_get_data_addr(t->tex[5].img, &t->tex[5].bpp,
			&t->tex[5].sizeline, &t->tex[5].endian);
	t->tex[6].img = mlx_xpm_file_to_image(t->window.mlx, "textures/gun2.xpm", &a, &b);
	t->tex[6].data = mlx_get_data_addr(t->tex[6].img, &t->tex[6].bpp,
			&t->tex[6].sizeline, &t->tex[6].endian);
	t->tex[7].img = mlx_xpm_file_to_image(t->window.mlx, "textures/gun3.xpm", &a, &b);
	t->tex[7].data = mlx_get_data_addr(t->tex[7].img, &t->tex[7].bpp,
			&t->tex[7].sizeline, &t->tex[7].endian);
	t->tex[8].img = mlx_xpm_file_to_image(t->window.mlx, "textures/gun4.xpm", &a, &b);
	t->tex[8].data = mlx_get_data_addr(t->tex[8].img, &t->tex[8].bpp,
			&t->tex[8].sizeline, &t->tex[8].endian);
	t->tex[9].img = mlx_xpm_file_to_image(t->window.mlx, "textures/gun5.xpm", &a, &b);
	t->tex[9].data = mlx_get_data_addr(t->tex[9].img, &t->tex[9].bpp,
			&t->tex[9].sizeline, &t->tex[9].endian);
	return (1);
}

static int				parse_line(t_cub3d *t, char *line)
{
	static int	map;
	int			i;

	map = !!map * map;
	if (!*line && !map)
		return (1);
	else if (map && *line && *line != '1')
		return ((t->nb_lines = map) & 0);
	i = -1;
	while (++i < (int)OPTIONS_PARSERS_SIZE)
		if (ft_strncmp(g_opt_p[i].id, line, ft_strlen(g_opt_p[i].id)) == 0)
		{
			if (*line == '1')
			{
				map = g_opt_p[i].func(t, line + g_opt_p[i].to_skip);
				if (map == -1)
					return ((map = 0) + 1);
				return (map);
			}
			else
				return (g_opt_p[i].func(t, line + g_opt_p[i].to_skip));
		}
	return (0);
}

static int				count_sprites(char *line)
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

static int				setup_map(t_cub3d *t, char *filename)
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
	if (*line == '1')
	{
		t->sprites_number += count_sprites(line);
		t->nb_lines++;
	}
	free(line);
	close(fd);
	return (!(ret == -1 || (!(t->map = (int **)malloc(sizeof(int *) *
		t->nb_lines)) || !(t->sprites = malloc(sizeof(t_sprites) *
		t->sprites_number)))));
}

int						parse(t_cub3d *t, char *filename)
{
	int		fd;
	int		ret;
	char	*line;

	t->map = NULL;
	t->ceilling_color.hexcode = 0;
	t->floor_color.hexcode = 0;
	if (!setup_map(t, filename) || (fd = open(filename, O_RDONLY)) < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!parse_line(t, line))
			return (0);
		free(line);
		line = NULL;
	}
	if (!parse_line(t, line))
		return (0);
	free(line);
	close(fd);
	if (ret == -1)
		return (0);
	setup_sky(t);
	setup_shotgun(t);
	return (1);
}
