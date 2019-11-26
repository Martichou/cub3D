/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:25:35 by marandre          #+#    #+#             */
/*   Updated: 2019/11/26 16:17:19 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define TITLE 				"cub3D"

# define WALL_N				0x3d3d3d
# define WALL_E				0x0B2D4B
# define WALL_S				0x32a852
# define WALL_W				0x38dbe0
# define AO					0x000000
# define D					(double)

typedef union
{
	unsigned int			hexcode;
	struct
	{
		unsigned char		empty;
		unsigned char		r;
		unsigned char		g;
		unsigned char		b;
	}						rgb;
}							t_color;

typedef struct				s_tex
{
	void					*img;
	char					*data;
	int						bpp;
	int						sizeline;
	int						endian;
}							t_tex;

typedef struct				s_cub3d
{
	t_tex					tex[10];
	void					*mlx;
	void					*win;
	void					*img;
	void					*img_ptr;
	int						**map;
	int						window_width;
	int						window_height;
	t_color					floor_color;
	t_color					ceilling_color;
	int						nb_lines;
	int						lenline;
	int						bpp;
	int						endian;
	int						sl;
	int						x_map;
	int						y_map;
	int						x_step;
	int						y_step;
	int						hit;
	int						side;
	int						lineheight;
	int						start;
	int						end;
	int						color;
	int						move_up;
	int						move_down;
	int						move_left;
	int						move_right;
	int						look_right;
	int						look_left;
	int						x_text;
	int						y_text;
	int						id;
	int						texture;
	int						x;
	int						y;
	int						min;
	int						max;
	int						shooting;
	int						fr;
	double					x_pos;
	double					y_pos;
	double					x_dir;
	double					y_dir;
	double					x_plane;
	double					y_plane;
	double					x_cam;
	double					x_raypos;
	double					y_raypos;
	double					x_raydir;
	double					y_raydir;
	double					x_sidedist;
	double					y_sidedist;
	double					x_deltadist;
	double					y_deltadist;
	double					walldist;
	double					x_olddir;
	double					x_oldplane;
	double					ms;
	double					rs;
	double					x_wall;
	double					x_floor;
	double					y_floor;
	double					curdist;
}							t_cub3d;

typedef int					(*t_option_parser_func)(t_cub3d *t, char *line);

typedef struct				s_option_parser
{
	char					*id;
	t_option_parser_func	func;
	int						to_skip;
}							t_option_parser;

/*
** Util's functions
*/
int							error_printf();
int							exit_program(t_cub3d *t);

/*
** Deplacement functions
*/
int							move(t_cub3d *t);
int							key_press(int keycode, t_cub3d *t);
int							key_release(int keycode, t_cub3d *t);
int							key_shoot(int keycode, t_cub3d *t);

/*
** Drawing functions
*/
void						ray(t_cub3d *t);
void						draw_wall(int x, int start, int end, t_cub3d *t);
void						draw_sky(t_cub3d *t);
void						draw_gun(t_cub3d *t);

/*
** Parsing functions
*/
int							parse(t_cub3d *t, char *filename);
int							parse_resolution(t_cub3d *t, char *line);
int							parse_map(t_cub3d *t, char *line);
int							parse_east_texture(t_cub3d *t, char *line);
int							parse_west_texture(t_cub3d *t, char *line);
int							parse_south_texture(t_cub3d *t, char *line);
int							parse_north_texture(t_cub3d *t, char *line);
int							parse_floor_color(t_cub3d *t, char *line);
int							parse_ceilling_color(t_cub3d *t, char *line);
int							parse_sprite_texture(t_cub3d *t, char *line);
int							setup_sky(t_cub3d *t);
int							setup_shotgun(t_cub3d *t);

/*
** AO
*/
int							ft_gt_colors(int clr1, int clr2, double val);
int							ft_shade_color(int clr, double val);
int							ft_add_ao(int clr, double percent);

#endif
