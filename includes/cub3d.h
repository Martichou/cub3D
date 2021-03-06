/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:25:35 by marandre          #+#    #+#             */
/*   Updated: 2019/12/13 01:31:01 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

# define TITLE 				"cub3D"
# define WALL_N				0x3d3d3d
# define WALL_E				0x0B2D4B
# define WALL_S				0x32a852
# define WALL_W				0x38dbe0
# define AO					0x000000
# define FOV				0.66
# define MS					0.05
# define RS					0.05
# ifndef M_PI
#  define M_PI				3.14
# endif
# define UDIV				2
# define VDIV				2
# define VMOVE				194.0
# define OFFSET				0.15

typedef union
{
	unsigned int			hexcode;
	struct
	{
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

typedef struct				s_sprites
{
	int						x;
	int						y;
	int						tex_index;
}							t_sprites;

typedef struct				s_sprites_work
{
	double					sp_x;
	double					sp_y;
	double					inv_det;
	double					transform_x;
	double					transform_y;
	int						sp_screen_x;
	int						vms;
	int						sp_height;
	int						draw_start_y;
	int						draw_end_y;
	int						sp_width;
	int						draw_start_x;
	int						draw_end_x;
	int						stripe;
	int						tex_x;
	int						y;
	int						d;
	int						tex_y;
	int						color;
}							t_sprites_work;

typedef struct				s_player
{
	short					life;
	short					bullets;
	char					*name;
	int						shooting;
	int						fr;
	short					reload;
	int						chest_collected;
	int						chest_to_collect;
	int						ended;
	double					x_pos;
	double					y_pos;
	double					x_dir;
	double					y_dir;
}							t_player;

typedef struct				s_other
{
	double					x_pos;
	double					y_pos;
}							t_other;

typedef struct				s_multi
{
	char					*address;
	int						socketfd;
	int						port;
	int						port_other;
	t_other					*other;
}							t_multi;

typedef struct				s_key
{
	int						move_up;
	int						move_down;
	int						move_left;
	int						move_right;
	int						look_right;
	int						look_left;
}							t_key;

typedef struct				s_window
{
	void					*mlx;
	void					*win;
	void					*img;
	void					*img_ptr;
	int						window_width;
	int						window_height;
	int						bpp;
	int						endian;
	int						sl;
}							t_window;

typedef struct				s_cub3d
{
	t_key					key;
	t_multi					multi;
	t_player				*player;
	t_tex					tex[13];
	t_sprites				*sprites;
	t_color					floor_color;
	t_color					ceilling_color;
	t_window				window;
	short					sprites_number;
	int						**map;
	int						nb_lines;
	int						lenline;
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
	int						x_text;
	int						y_text;
	int						id;
	int						texture;
	int						x;
	int						y;
	int						min;
	int						max;
	double					*zbuffer;
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
int							error_printf(t_cub3d *t);
int							exit_program(t_cub3d *t);
void						fps(t_cub3d *e);
void						sort_sprites(int *order, double *dist, int amount);
int							save_bmp(t_cub3d *t);

/*
** Deplacement functions
*/
int							move(t_cub3d *t);
int							key_press(int keycode, t_cub3d *t);
int							key_release(int keycode, t_cub3d *t);

/*
** Drawing functions
*/
void						ray(t_cub3d *t);
void						draw_wall(int x, int start, int end, t_cub3d *t);
void						draw_sky(t_cub3d *t);
void						draw_gun(t_cub3d *t);
int							draw_sprites(t_cub3d *t);

/*
** DDA functions
*/
void						dda_init(t_cub3d *t);
void						dda(t_cub3d *t);

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
int							parse_sprite_texture_10(t_cub3d *t, char *line);
int							parse_sprite_texture_11(t_cub3d *t, char *line);
int							setup_sky(t_cub3d *t);
int							setup_barrel(t_cub3d *t);

/*
** Socket multi
*/
int							socket_frame(t_cub3d *t);
int							socket_init(t_cub3d *t);
int							send_movement(t_cub3d *t, int bypass);

/*
** Draw player
*/
int							draw_player(t_cub3d *t);

#endif
