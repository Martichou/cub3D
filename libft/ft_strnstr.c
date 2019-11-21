/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:49:00 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:08:36 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Find first occurance of neddle in haystack but no more than len
** returning a pointer to the first character of the first occurance
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (*needle)
	{
		i = 0;
		while (haystack[i] && i < len)
		{
			if (haystack[i] == needle[0])
			{
				j = 1;
				while (i + j < len && needle[j] && haystack[i + j] == needle[j])
				{
					j++;
				}
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
			i++;
		}
		return (0);
	}
	return ((char *)haystack);
}
