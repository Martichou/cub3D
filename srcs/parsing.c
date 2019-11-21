/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:50:31 by marandre          #+#    #+#             */
/*   Updated: 2019/11/21 21:15:14 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

static size_t	ft_linelen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] && s[count] != '\n')
		count++;
	return (count);
}

static int		ft_countlines(char *str)
{
	int		lines;

	lines = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return (lines);
}

static int		check_map(char *buff, t_cub3d *t)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	t->lenline = ft_linelen(buff);
	t->nb_lines = ft_countlines(buff);
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if (len - 1 != t->lenline)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

static int		parser2(t_cub3d *t, char *filename)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(t->map[i] = (int *)malloc(sizeof(int) * t->lenline)))
			return (0);
		while (++j < t->lenline)
		{
			if (str[k] == ' ')
				k++;
			t->map[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		free(str);
	}
	return (1);
}

static int		check_side(t_cub3d *t)
{
	int		i;

	i = 0;
	while (i < t->lenline)
	{
		if (t->map[0][i] == 0)
			return (0);
		if (t->map[t->nb_lines - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < t->nb_lines)
	{
		if (t->map[i][0] == 0)
			return (0);
		if (t->map[i][t->lenline - 1] == 0)
			return (0);
		i++;
	}
	// For spawing position as of now
	if (t->map[3][3] != 0)
		return (0);
	return (1);
}

int		parsing(t_cub3d *t, char *filename)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_calloc(sizeof(char), 65536);
	fd = open(filename, O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
	{
		ft_putstr_fd("cub3d: ", STDOUT_FILENO);
		ft_putstr_fd(filename, STDOUT_FILENO);
		ft_putstr_fd(": No such file\n", STDOUT_FILENO);
		return (0);
	}
	if (!(check_map(buff, t)))
	{
		ft_putstr_fd("Map error\n", STDOUT_FILENO);
		return (0);
	}
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			t->lenline--;
		i++;
	}
	ft_strdel(&buff);
	close(fd);
	if (!(t->map = (int **)malloc(sizeof(int *) * t->nb_lines))
			|| !(parser2(t, filename)))
		return (0);
	if (!check_side(t))
	{
		ft_putstr_fd("Map error\n", STDOUT_FILENO);
		return (0);
	}
	return (1);
}