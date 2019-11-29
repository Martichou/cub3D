/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:13:11 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 15:18:24 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_double(double *xp, double *yp)
{
	if (xp == yp)
		return ;
	*xp = *xp + *yp;
	*yp = *xp - *yp;
	*xp = *xp - *yp;
}

void	swap_int(int *xp, int *yp)
{
	if (xp == yp)
		return ;
	*xp = *xp + *yp;
	*yp = *xp - *yp;
	*xp = *xp - *yp;
}
