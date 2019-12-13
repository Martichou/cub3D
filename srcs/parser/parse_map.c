/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:01:10 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:25:49 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#define J 0
#define SPACE 1
#define K 2
#define I 3

static int	exit_parse_map(t_cub3d *t, int i)
{
	t->nb_lines = i;
	return (0);
}

static int	set_player_pos(t_cub3d *t, char line, int i, int j)
{
	if (line == 'N' || line == 'S')
	{
		t->player->x_dir = (line == 'N') ? -1 : 1;
		t->player->y_dir = 0.;
		t->x_plane = 0.;
		t->y_plane = (line == 'N') ? FOV : -FOV;
	}
	else
	{
		t->player->x_dir = 0.;
		t->player->y_dir = (line == 'E') ? 1. : -1.;
		t->x_plane = (line == 'E') ? FOV : -FOV;
		t->y_plane = 0.;
	}
	if (t->player->x_pos || t->player->y_pos)
		return (0);
	t->player->x_pos = i;
	t->player->y_pos = j;
	t->map[i][j] = 0;
	return (1);
}

static int	saved_parsed(t_cub3d *t, char line, int *tab, int *sp)
{
	if (tab[K] == 0 && line != '1')
		return (exit_parse_map(t, tab[I]));
	else if (ft_strchr("NESW", line))
	{
		if (!set_player_pos(t, line, tab[I], tab[J]))
			return (exit_parse_map(t, tab[I]));
	}
	else if (ft_strchr("0123", line))
	{
		t->map[tab[I]][tab[J]] = ft_natoi(&line, 1);
		if (t->map[tab[I]][tab[J]] == 2 || t->map[tab[I]][tab[J]] == 3)
		{
			t->player->chest_to_collect += (t->map[tab[I]][tab[J]] == 2);
			if (*sp > 0)
			{
				t->sprites[--*sp].x = tab[I];
				t->sprites[*sp].y = tab[J];
				t->sprites[*sp].tex_index = 10 + (t->map[tab[I]][tab[J]] == 3);
			}
		}
	}
	else
		return (exit_parse_map(t, tab[I]));
	return (1);
}

static int	check_validity_and_init_tab
	(t_cub3d *t, char *line, int *i, int *tab)
{
	if (!t->lenline)
		t->lenline = ft_linelen(line);
	else if (t->lenline != ft_linelen(line))
		return (0);
	if (!(t->map[*i] = (int *)malloc(sizeof(int) * t->lenline)))
		return (0);
	if (!*i)
		*i = 0;
	tab[K] = 0;
	tab[SPACE] = 0;
	tab[J] = -1;
	tab[I] = *i;
	return (1);
}

int			parse_map(t_cub3d *t, char *line)
{
	static int	sp;
	static int	i;
	int			tab[4];

	if (!check_validity_and_init_tab(t, line, &i, tab))
		return (exit_parse_map(t, i));
	if (!sp)
		sp = t->sprites_number;
	while (++tab[J] < t->lenline)
	{
		if ((line[tab[K]] != '1' && line[tab[K]] != ' ') &&
		(!i || i == t->nb_lines - 1 || tab[K] - tab[SPACE] == t->lenline - 1))
			return (exit_parse_map(t, i));
		while (line[tab[K]] == ' ' && ++tab[K])
			tab[SPACE]++;
		if (!saved_parsed(t, line[tab[K]], tab, &sp))
			return (exit_parse_map(t, i));
		tab[K]++;
	}
	i++;
	if (i == t->nb_lines)
		return (-1);
	return (i);
}
