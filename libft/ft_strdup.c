/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:47:41 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:11:15 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

/*
** Create a copy of s
*/

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	i;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	i = 0;
	while (*s)
		result[i++] = *s++;
	result[i] = '\0';
	return (result);
}
