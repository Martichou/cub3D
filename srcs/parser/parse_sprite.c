/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:27:41 by marandre          #+#    #+#             */
/*   Updated: 2019/12/09 21:11:12 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	parse_sprite_texture_10(t_cub3d *t, char *line)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[10].img = mlx_xpm_file_to_image(t->mlx, ft_strdup(line + 1), &a, &b);
	t->tex[10].data = mlx_get_data_addr(t->tex[10].img, &t->tex[10].bpp,
			&t->tex[10].sizeline, &t->tex[10].endian);
	return (1);
}

int	parse_sprite_texture_11(t_cub3d *t, char *line)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[11].img = mlx_xpm_file_to_image(t->mlx, ft_strdup(line + 1), &a, &b);
	t->tex[11].data = mlx_get_data_addr(t->tex[11].img, &t->tex[11].bpp,
			&t->tex[11].sizeline, &t->tex[11].endian);
	return (1);
}
