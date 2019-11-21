/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:03:11 by marandre          #+#    #+#             */
/*   Updated: 2019/11/21 21:01:25 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c1;
	char	*c2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	c1 = (char*)s1;
	c2 = (char*)s2;
	if (!(res = (char*)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(res, c1);
	ft_strcat(res, c2);
	free((void*)s1);
	return (res);
}
