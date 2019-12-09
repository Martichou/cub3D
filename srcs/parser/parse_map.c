/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:01:10 by marandre          #+#    #+#             */
/*   Updated: 2019/12/09 16:44:12 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	exit_parse_map(t_cub3d *t, int i)
{
	t->nb_lines = i;
	return (0);
}

static int	ft_linelen(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\n')
			count++;
		s++;
	}
	return (count + 1 / 2);
}

int			parse_map(t_cub3d *t, char *line)
{
	static int sp;
	static int i;
	int j;
	int k;

	if (!i)
		i = 0;
	k = 0;
	if (!t->lenline)
		t->lenline = ft_linelen(line);
	else if (t->lenline != ft_linelen(line))
		return (exit_parse_map(t, i));
	if (!(t->map[i] = (int *)malloc(sizeof(int) * t->lenline)))
		return (exit_parse_map(t, i));
	j = -1;
	if (!sp)
		sp = t->sprites_number;
	while (++j < t->lenline)
	{
		while (line[k] == ' ')
			k++;
		if (k == 0 && line[k] != '1')
			return (exit_parse_map(t, i));
		else if (line[k] == 'N' || line[k] == 'E'
			|| line[k] == 'S' || line[k] == 'W')
		{
			if (line[k] == 'N')
			{
				t->x_dir = -1;
				t->y_dir = 0.;
				t->x_plane = 0.;
				t->y_plane = FOV;
			}
			else if (line[k] == 'S')
			{
				t->x_dir = 1;
				t->y_dir = 0.;
				t->x_plane = 0.;
				t->y_plane = -FOV;
			}
			else if (line[k] == 'E')
			{
				t->x_dir = 0.;
				t->y_dir = 1.;
				t->x_plane = FOV;
				t->y_plane = 0.;
			}
			else if (line[k] == 'W')
			{
				t->x_dir = 0.;
				t->y_dir = -1.;
				t->x_plane = -FOV;
				t->y_plane = 0.;
			}
			t->x_pos = i;
			t->y_pos = j;
			t->map[i][j] = 0;
		}
		else if (line[k] == '0' || line[k] == '1' || line[k] == '2' || line[k] == '3')
		{
			t->map[i][j] = ft_atoi(&line[k]);
			if (t->map[i][j] == 2 || t->map[i][j] == 3)
			{
				if (t->map[i][j] == 2)
					t->player->chest_to_collect++;
				if (sp > 0)
				{
					t->sprites[sp - 1].x = i;
					t->sprites[sp - 1].y = j;
					if (t->map[i][j] == 2)
						t->sprites[sp - 1].tex_index = 10;
					else if (t->map[i][j] == 3)
						t->sprites[sp - 1].tex_index = 11;
					sp--;
				}
			}
		}
		else
			return (exit_parse_map(t, i));
		k++;
	}
	i++;
	if (i == t->nb_lines)
		return (-1);
	return (i);
}