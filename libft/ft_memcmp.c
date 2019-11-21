/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:54:44 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:12:49 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compare s1 and s2 for n bytes and return which is bigger
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int res;

	res = 0;
	while (n-- > 0 && !res)
		res = *(unsigned char *)s1++ - *(unsigned char *)s2++;
	return (res);
}
