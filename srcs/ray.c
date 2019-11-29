/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:47:52 by marandre          #+#    #+#             */
/*   Updated: 2019/11/29 14:59:42 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	dda_init(t_cub3d *t)
{
	t->x_deltadist = sqrt(1 + (t->y_raydir * t->y_raydir)
			/ (t->x_raydir * t->x_raydir));
	t->y_deltadist = sqrt(1 + (t->x_raydir * t->x_raydir)
			/ (t->y_raydir * t->y_raydir));
	if (t->x_raydir < 0 && (t->x_step = -1))
		t->x_sidedist = (t->x_raypos - t->x_map) * t->x_deltadist;
	else if ((t->x_step = 1))
		t->x_sidedist = (t->x_map + 1.0 - t->x_raypos) * t->x_deltadist;
	if (t->y_raydir < 0 && (t->y_step = -1))
		t->y_sidedist = (t->y_raypos - t->y_map) * t->y_deltadist;
	else if ((t->y_step = 1))
		t->y_sidedist = (t->y_map + 1.0 - t->y_raypos) * t->y_deltadist;
}

static void	dda(t_cub3d *t)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->x_sidedist < t->y_sidedist)
		{
			t->x_sidedist += t->x_deltadist;
			t->x_map += t->x_step;
			if (t->x_pos > t->x_map)
			{
				t->side = 0;
				t->color = WALL_N;
			}
			else
			{
				t->side = 1;
				t->color = WALL_S;
			}
			t->color = ft_gt_colors(t->color, AO, ((t->x_sidedist / 7) / ((4. - (2. * (float)(1))) - 0.4)));
		}
		else
		{
			t->y_sidedist += t->y_deltadist;
			t->y_map += t->y_step;
			if (t->y_pos > t->y_map)
			{
				t->side = 2;
				t->color = WALL_W;
			}
			else
			{
				t->side = 3;
				t->color = WALL_E;
			}
			t->color = ft_gt_colors(t->color, AO, ((t->y_sidedist / 7) / ((4. - (2. * (float)(1))) - 0.4)));
		}
		if (t->map[t->x_map][t->y_map] > 0)
			t->hit = 1;
	}
}

static void	ray_casting_init(t_cub3d *t, int x)
{
	t->x_cam = 2 * x / (double)(t->window_width) - 1;
	t->x_raypos = t->x_pos;
	t->y_raypos = t->y_pos;
	t->x_raydir = t->x_dir + t->x_plane * t->x_cam;
	t->y_raydir = t->y_dir + t->y_plane * t->x_cam;
	t->x_map = (int)t->x_raypos;
	t->y_map = (int)t->y_raypos;
	dda_init(t);
	dda(t);
	if (t->side == 0 || t->side == 1)
		t->walldist = (t->x_map - t->x_raypos +
				(1 - t->x_step) / 2) / t->x_raydir;
	else
		t->walldist = (t->y_map - t->y_raypos +
				(1 - t->y_step) / 2) / t->y_raydir;
}

static void	floor_and_ceiling(t_cub3d *t, int x)
{
	if (t->texture == 0)
	{
		if (t->start > 0)
		{
			t->color = AO;
			t->y = -1;
			if (x < t->window_width && t->y < t->window_height)
				while (++t->y < t->start)
				{
					//t->color = ft_add_ao(0xc9c3c3, ((t->y - t->min) * 100. / (t->max - t->min)));					
					ft_memcpy(t->img_ptr + 4 * t->window_width * t->y + x * 4, &t->color, sizeof(int));
				}
		}
	}
	if (t->end > 0)
	{

		t->color = AO;
		t->y = t->end - 1;
		if (x < t->window_width && t->y < t->window_height)
			while (++t->y < t->window_height)
			{
				//t->color = ft_gt_colors(t->color, AO, ((((t->x_sidedist + t->y_sidedist) / 2) / 5) / ((4. - (2. * (float)(1))) - 0.4)));
				ft_memcpy(t->img_ptr + 4 * t->window_width * t->y + x * 4, &t->color, sizeof(int));
			}
	}
}

void swap_double(double* xp, double* yp) 
{ 
    if (xp == yp) // Check if the two addresses are same 
        return; 
    *xp = *xp + *yp; 
    *yp = *xp - *yp; 
    *xp = *xp - *yp; 
}

void swap_int(int* xp, int* yp) 
{ 
    if (xp == yp) // Check if the two addresses are same 
        return; 
    *xp = *xp + *yp; 
    *yp = *xp - *yp; 
    *xp = *xp - *yp; 
} 

void combSort(int* order, double* dist, int amount)
{
	int gap = amount;
	int swapped = 0;
	while(gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if(gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		for (int i = 0; i < amount - gap; i++)
		{
			int j = i + gap;
			if (dist[i] < dist[j])
			{
				swap_double(&dist[i], &dist[j]);
				swap_int(&order[i], &order[j]);
				swapped = 1;
			}
		}
	}
}

static void	draw_sprites(t_cub3d *t)
{
	int spriteOrder[t->sprites_number];
	double spriteDistance[t->sprites_number];
	int i;
	
	i = 0;
	while (i < t->sprites_number)
	{
		spriteOrder[i] = i;
    	spriteDistance[i] = ((t->x_pos - t->sprites[i].x) * (t->x_pos - t->sprites[i].x) + (t->y_pos - t->sprites[i].y) * (t->y_pos - t->sprites[i].y));
		i++;
	}
	combSort(spriteOrder, spriteDistance, t->sprites_number);

	i = 0;
	while (i < t->sprites_number)
	{
		//translate sprite position to relative to camera
		//printf("order is %d\n i is %d\n X is %f\n Y is %f\n", spriteOrder[i], i, t->sprites[i].x, t->sprites[i].y);
		double spriteX = t->sprites[spriteOrder[i]].x + 0.5 - t->x_pos;
		double spriteY = t->sprites[spriteOrder[i]].y + 0.5 - t->y_pos;

		double invDet = 1.0 / (t->x_plane * t->y_dir - t->x_dir * t->y_plane); //required for correct matrix multiplication

		double transformX = invDet * (t->y_dir * spriteX - t->x_dir * spriteY);
		double transformY = invDet * (-t->y_plane * spriteX + t->x_plane * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		int spriteScreenX = (int)((t->window_width / 2) * (1 + transformX / transformY));

		//parameters for scaling and moving the sprites
		#define uDiv 2
		#define vDiv 2
		#define vMove 192.0
		int vMoveScreen = (int)(vMove / transformY);

		//calculate height of the sprite on screen
		int spriteHeight = abs((int)(t->window_height / (transformY))) / vDiv; //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + t->window_height / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + t->window_height / 2 + vMoveScreen;
		if(drawEndY >= t->window_height) drawEndY = t->window_height - 1;

		//calculate width of the sprite
		int spriteWidth = abs( (int) (t->window_height / (transformY))) / uDiv;
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= t->window_width) drawEndX = t->window_width - 1;

		//loop through every vertical stripe of the sprite on screen
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
			if(transformY > 0 && stripe > 0 && stripe < t->window_width && transformY < t->zbuffer[stripe])
				for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y-vMoveScreen) * 256 - t->window_height * 128 + spriteHeight * 128;
					int texY = ((d * 64) / spriteHeight) / 256;
					int color = t->tex[10].data[texY % 64 * t->tex[10].sizeline + texX % 64 * t->tex[10].bpp / 8];
					if((color & 0x00FFFFFF) != 0)
						ft_memcpy(t->img_ptr + 4 * t->window_width * y + stripe * 4, &t->tex[10].data[texY % 64 * t->tex[10].sizeline + texX % 64 * t->tex[10].bpp / 8], sizeof(int));
				}
		}
		i++;
	}
}

void	ray(t_cub3d *t)
{
	t->x = -1;
	t->img = mlx_new_image(t->mlx, t->window_width, t->window_height);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
	if (t->texture == 1)
		draw_sky(t);
	while (++t->x < t->window_width)
	{
		ray_casting_init(t, t->x);
		t->lineheight = (int)(t->window_height / t->walldist);
		t->start = -t->lineheight / 2 + t->window_height / 2;
		if (t->start < 0)
			t->start = 0;
		t->end = t->lineheight / 2 + t->window_height / 2;
		if (t->end >= t->window_height)
			t->end = t->window_height - 1;
		t->min = ((t->window_height / 2) - t->lineheight);
		t->max = ((t->window_height / 2) + t->lineheight);
		t->zbuffer[t->x] = t->walldist;
		draw_wall(t->x, t->start - 1, t->end, t);
		floor_and_ceiling(t, t->x);
	}
	draw_sprites(t);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
}