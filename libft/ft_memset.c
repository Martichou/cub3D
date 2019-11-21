/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:25:10 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 16:08:55 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy value of c in n first characters of object pointed by s
** Need to crash when no more p or not?
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	p = s;
	while (n-- > 0)
		*p++ = (unsigned char)c;
	return (s);
}
