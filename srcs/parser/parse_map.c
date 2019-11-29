/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:01:10 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 19:35:45 by marandre         ###   ########.fr       */
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