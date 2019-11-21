/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:37:44 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:04:02 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Append src to end of dst and append at most size - strlen(dst) - 1
** null terminating the result
** return dst length plus length of src
** while (n-- != 0 && *d) + 2 lines is to
** Find the end of dst and adjust bytes left but don't go past end
** d is the last char/pointer of dst or \0 if dst is large enought
** n is number of place free in dst
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	result;
	size_t	size_dest;

	result = ft_strlen(src);
	size_dest = 0;
	while (dst[size_dest] && size > size_dest)
		size_dest++;
	i = 0;
	while (src[i] && size > size_dest && i < (size - size_dest - 1))
	{
		dst[size_dest + i] = src[i];
		i++;
	}
	if (size > size_dest)
		dst[size_dest + i] = '\0';
	result += size_dest;
	return (result);
}
