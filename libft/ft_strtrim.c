/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:05:10 by marandre          #+#    #+#             */
/*   Updated: 2019/10/10 17:37:45 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

/*
** Remove the set from the begin or the end of the s1
** return res which is same as s1 without set
** l is since of s1 after skipped set at the begin
** if l to prevent error if full blank
*/

char			*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	size_t			s;
	size_t			l;

	if (!s1 || !set)
		return (NULL);
	s = 0;
	while (s1[s] && ft_strchr(set, s1[s]) != NULL)
		s++;
	l = ft_strlen(&s1[s]);
	if (l)
		while (s1[s + l - 1] && ft_strchr(set, s1[s + l - 1]) != 0)
			l--;
	if (!(res = malloc(sizeof(char) * (l + 1))))
		return (res);
	res = ft_strncpy(res, &s1[s], l);
	res[l] = '\0';
	return (res);
}
