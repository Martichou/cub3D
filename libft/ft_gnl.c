/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:58:37 by marandre          #+#    #+#             */
/*   Updated: 2019/11/21 21:00:05 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_char(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

static size_t	ft_strlen_gnl(char *s, int gnl)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n' && gnl)
			return (i);
		i++;
	}
	return (i);
}

static int		ft_strdel(char **as, char **str, int frenum, int ret)
{
	if (!(as == NULL))
	{
		free(*as);
		*as = NULL;
	}
	if (frenum == 2)
	{
		if (!(str == NULL))
		{
			free(*str);
			*str = NULL;
		}
	}
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char		*s[OPEN_MAX];
	char			*buf;
	char			*tmp;
	int				ret;

	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!s[fd] && !(s[fd] = ft_calloc(1, sizeof(char *))))
		return (-1);
	while ((ft_char('\n', s[fd])) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		s[fd] = ft_strjoin(s[fd], buf);
	}
	*line = ft_substr(s[fd], 0, ft_strlen_gnl(s[fd], 1));
	if ((ft_char('\n', s[fd])) < 0)
		return (ft_strdel(&s[fd], &buf, 2, 0));
	tmp = s[fd];
	s[fd] = ft_substr(s[fd], ft_char('\n', s[fd]) + 1, ft_strlen_gnl(s[fd], 0));
	return (ft_strdel(&tmp, &buf, 2, 1));
}