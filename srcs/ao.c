/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ao.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:30:54 by marandre          #+#    #+#             */
/*   Updated: 2019/12/04 16:56:09 by marandre         ###   ########.fr       */
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
	r = floor((double)((clr1 >> 16) & 0xFF) -
		(((double)((clr1 >> 16) & 0xFF) - (double)((clr2 >> 16) & 0xFF)) * val));
	g = floor((double)((clr1 >> 8) & 0xFF) -
		(((double)((clr1 >> 8) & 0xFF) - (double)((clr2 >> 8) & 0xFF)) * val));
	b = floor((double)((clr1) & 0xFF) -
		(((double)((clr1) & 0xFF) - (double)((clr2) & 0xFF)) * val));
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
	r = floor((double)((clr >> 16) & 0xFF) +
		(double)((0.0 - (double)((clr >> 16) & 0xFF)) * val));
	g = floor((double)((clr >> 8) & 0xFF) +
		(double)((0.0 - (double)((clr >> 8) & 0xFF)) * val));
	b = floor((double)((clr) & 0xFF) +
		(double)((0.0 - (double)((clr) & 0xFF)) * val));
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}