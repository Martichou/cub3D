/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ao.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:30:54 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 20:09:54 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int			ft_gt_colors(int clr1, int clr2, double val)
{
	int		r;
	int		g;
	int		b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr1 >> 16) & 0xFF) -
	((D((clr1 >> 16) & 0xFF) - D((clr2 >> 16) & 0xFF)) * val));
	g = floor(D((clr1 >> 8) & 0xFF) -
	((D((clr1 >> 8) & 0xFF) - D((clr2 >> 8) & 0xFF)) * val));
	b = floor(D((clr1) & 0xFF) - ((D((clr1) & 0xFF) - D((clr2) & 0xFF)) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int			ft_shade_color(int clr, double val)
{
	int		r;
	int		g;
	int		b;

	if (val > 1.0)
		val = 1.0;
	else if (val < 0.0)
		val = 0.0;
	r = floor(D((clr >> 16) & 0xFF) + D((0.0 - D((clr >> 16) & 0xFF)) * val));
	g = floor(D((clr >> 8) & 0xFF) + D((0.0 - D((clr >> 8) & 0xFF)) * val));
	b = floor(D((clr) & 0xFF) + D((0.0 - D((clr) & 0xFF)) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}