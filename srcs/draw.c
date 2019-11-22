/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:51:23 by marandre          #+#    #+#             */
/*   Updated: 2019/11/22 21:04:24 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_pxl_to_img(t_cub3d *t, int x, int y, int color)
{
	if (x < WINX && y < WINY)
		ft_memcpy(t->img_ptr + 4 * WINX * y + x * 4,
				&color, sizeof(int));
}

void	draw_wall(int x, int start, int end, t_cub3d *t)
{
	while (++start <= end)
		put_pxl_to_img(t, x, start, t->color);
}