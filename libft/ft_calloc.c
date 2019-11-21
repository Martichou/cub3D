/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:51 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 15:54:12 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(unsigned int nmemb, size_t size)
{
	void			*p;
	size_t			total;

	total = nmemb * size;
	if (!(p = malloc(total)))
		return (NULL);
	while (total-- > 0)
		*(unsigned char *)p++ = 0;
	return (p - nmemb * size);
}
