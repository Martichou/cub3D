/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:41:56 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 16:29:29 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locate first occurance of c in str even if it's the \0
** return pointer to the first occurance
*/

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	str += len;
	while (i <= len)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
		i++;
	}
	return (0);
}
