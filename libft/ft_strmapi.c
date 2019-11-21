/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:13:01 by marandre          #+#    #+#             */
/*   Updated: 2019/10/10 17:37:29 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Apply f to each character and create nez string resulting
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (!(res = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
