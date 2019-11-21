/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:43:41 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 16:23:32 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int res;

	res = 0;
	while (!res && n-- > 0 && (*s1 || *s2))
	{
		res = (unsigned char)*s1++ - (unsigned char)*s2++;
	}
	return (res);
}
