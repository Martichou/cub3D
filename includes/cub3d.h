/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:25:35 by marandre          #+#    #+#             */
/*   Updated: 2019/11/21 20:53:54 by marandre         ###   ########.fr       */
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

# define ep error_printf()
# define WINX 1024
# define WINY 768
# define TITLE "cub3D"

typedef struct	s_tex
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tex;

typedef struct	s_cub3d
{
	t_tex		tex[9];
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			**map;
	int			nb_lines;
	int			lenline;
	int			bpp;
	int			endian;
	int			sl;
	int			x_map;
	int			y_map;
	int			x_step;
	int			y_step;
	int			hit;
	int			side;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			x_text;
	int			y_text;
	int			id;
	int			texture;
	int			x_floortext;
	int			y_floortext;
	int			x;
	int			y;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		x_cam;
	double		x_raypos;
	double		y_raypos;
	double		x_raydir;
	double		y_raydir;
	double		x_sidedist;
	double		y_sidedist;
	double		x_deltadist;
	double		y_deltadist;
	double		walldist;
	double		x_olddir;
	double		x_oldplane;
	double		ms;
	double		rs;
	double		x_wall;
	double		x_floor;
	double		y_floor;
	double		x_curfloortext;
	double		y_curfloortext;
	double		curdist;
	double		weight;
}				t_cub3d;

/*
** util's functions
*/
int		error_printf();
int		exit_program(t_cub3d *t);

int		parsing(t_cub3d *t, char *filename);

int		move(t_cub3d *t);
int		key_press(int keycode, t_cub3d *t);
int		key_release(int keycode, t_cub3d *t);

void	ray(t_cub3d *t);
void	draw_wall(int x, int start, int end, t_cub3d *t);
void	draw_sky(t_cub3d *t);
void	draw_floor(t_cub3d *t);

#endif
