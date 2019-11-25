/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:48:07 by marandre          #+#    #+#             */
/*   Updated: 2019/11/25 22:16:02 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_north_texture(t_cub3d *t, char *line)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[0].img = mlx_xpm_file_to_image(t->mlx, ft_strdup(line + 1), &a, &b);
	t->tex[0].data = mlx_get_data_addr(t->tex[0].img, &t->tex[0].bpp,
			&t->tex[0].sizeline, &t->tex[0].endian);
	return (1);
}

int	parse_south_texture(t_cub3d *t, char *line)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[1].img = mlx_xpm_file_to_image(t->mlx, ft_strdup(line + 1), &a, &b);
	t->tex[1].data = mlx_get_data_addr(t->tex[1].img, &t->tex[1].bpp,
			&t->tex[1].sizeline, &t->tex[1].endian);
	return (1);
}

int	parse_west_texture(t_cub3d *t, char *line)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[2].img = mlx_xpm_file_to_image(t->mlx, ft_strdup(line + 1), &a, &b);
	t->tex[2].data = mlx_get_data_addr(t->tex[2].img, &t->tex[2].bpp,
			&t->tex[2].sizeline, &t->tex[2].endian);
	return (1);
}

int	parse_east_texture(t_cub3d *t, char *line)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[3].img = mlx_xpm_file_to_image(t->mlx, ft_strdup(line + 1), &a, &b);
	t->tex[3].data = mlx_get_data_addr(t->tex[3].img, &t->tex[3].bpp,
			&t->tex[3].sizeline, &t->tex[3].endian);
	return (1);
}

int	setup_sky(t_cub3d *t)
{
	int		a;
	int		b;

	a = 512;
	b = 512;
	t->tex[4].img = mlx_xpm_file_to_image(t->mlx, "textures/sky.xpm", &a, &b);
	t->tex[4].data = mlx_get_data_addr(t->tex[4].img, &t->tex[4].bpp,
			&t->tex[4].sizeline, &t->tex[4].endian);
	return (1);
}