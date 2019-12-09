/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_natoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:29:17 by marandre          #+#    #+#             */
/*   Updated: 2019/12/09 17:29:57 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_natoi(const char *str, int len)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && (len != -2 && len > 0))
	{
		--len;
		if (10 * result + str[i] - 48 >= result)
			result = 10 * result + str[i++] - 48;
		else
			return (sign == 1 ? (int)LONG_MAX
					: (int)-LONG_MAX - 1);
	}
	return ((int)(sign * result));
}
