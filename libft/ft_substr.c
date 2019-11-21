/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:40:08 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:33:48 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Return substring from string, begin at start and size of max len
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) != 0)
	{
		if (start < ft_strlen(s))
			while (i < len && *(s + start + i))
			{
				result[i] = *(s + start + i);
				i++;
			}
		result[i] = '\0';
	}
	return (result);
}
