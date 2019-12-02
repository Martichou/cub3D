/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:01:10 by marandre          #+#    #+#             */
/*   Updated: 2019/12/03 00:00:34 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

int	parse_map(t_cub3d *t, char *line)
{
	static int i;
	int j;
	int k;
	static int sp;

	if (!i)
		i = 0;
	k = 0;
	if (t->lenline != -1)
		t->lenline = ft_linelen(line);
	else if (t->lenline != ft_linelen(line))
		return (0);
	if (!(t->map[i] = (int *)malloc(sizeof(int) * t->lenline)))
		return (0);
	j = -1;
	if (!sp)
		sp = t->sprites_number;
	while (++j < t->lenline)
	{
		if (line[k] == ' ')
			k++;
		if (line[k] == 'N' || line[k] == 'E'
			|| line[k] == 'S' || line[k] == 'W')
		{
			// N = -1	S = 1		E = 0.		W = 0.
			// N = 0.	S = 0.		E = 1.		W = -1.
			// N = 0.	S = 0.		E = FOV		W = -FOV
			// N = FOV	S = -FOV	E = 0.		W = 0.
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
		else
		{
			t->map[i][j] = ft_atoi(&line[k]);
			if (t->map[i][j] == 2 || t->map[i][j] == 3)
			{
				// Save the sprites and x and y and increment counter of sprites
				if (sp > 0)
				{
					t->sprites[sp - 1].x = i;
					t->sprites[sp - 1].y = j;
					if (t->map[i][j] == 2)
						t->sprites[sp - 1].tex_index = 10;
					else if (t->map[i][j] == 3)
						t->sprites[sp - 1].tex_index = 11;
					t->map[i][j] = 0;
					sp--;
				}
			}
		}
		k++;
	}
	i++;
	return (1);
}