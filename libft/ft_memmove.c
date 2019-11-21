/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:35:10 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:13:19 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy src to dest for n bytes
**
**1) <-----s----->                start at end of s
**                 <-----d----->
**
**2) <-----s----->                start at end of s
**            <-----d----->
**
**3) <-----s----->                no action
**   <-----d----->
**
**4)          <-----s----->       start at beginning of s
**   <-----d----->
**
**5)               <-----s----->  start at beginning of s
**   <-----d----->
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	buff[n];

	if (!dest && !src)
		return (0);
	ft_memcpy(buff, src, n);
	ft_memcpy(dest, buff, n);
	return (dest);
}
