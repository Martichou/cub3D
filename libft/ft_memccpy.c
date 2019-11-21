/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:32:01 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 16:36:01 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy at most len bytes fron src to dest and stop once it find c
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	int	s;

	s = 0;
	while (len > 0 && !s)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
		{
			s = 1;
		}
		len--;
	}
	if (s == 0)
	{
		return (0);
	}
	else
	{
		return (dest);
	}
}
