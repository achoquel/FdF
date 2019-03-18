/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:53:35 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/24 10:00:18 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../srcs/libft/includes/libft.h"

# define PI 3.14159265358979323846
# define WSTAT env->win_status
# define WHITE 0xFFFFFF
# define STA_R 0xFC0740
# define STA_L 0xFF5179

typedef struct	s_utils_circle
{
	int			xc;
	int			yc;
	int			x;
	int			y;
}				t_circle;

typedef struct	s_utils_key
{
	void		*id;
	void		*win;
	char		*is;
	char		*help;
	int			color;
}				t_key;

typedef struct	s_utils_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_utils_size
{
	int			w;
	int			h;
}				t_size;

typedef struct	s_img
{
	void		*img_id;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx_id;
	void		*win_main;
	void		*win_help;
	void		*win_status;
	int			mx;
	int			my;
	int			hx;
	int			hy;
	int			sx;
	int			sy;
	int			color;
	int			x;
	int			y;
	int			x2;
	int			y2;
	int			z;
	int			z2;
	int			dx;
	int			dy;
	int			xincr;
	int			yincr;
	int			err;
	int			tmperr;
	char		*map;
	char		**fmap;
	int			fd;
	int			rot;
	int			zoom;
	int			xcam;
	int			ycam;
	int			r;
	int			g;
	int			b;
	int			alt;
	int			state;
	int			xmax;
	int			ymax;
	int			theme;
	int			perspective;
	t_img		img;
}				t_env;

int				main_hooks(int key, t_env *env);
int				fdf_parser(t_env *env);
void			help_init(t_env *env);
void			status_init(t_env *env);
void			waiting_screen(t_env *env);
void			draw_rectangle(void *mlx_id, void *win_id, t_pos *pos, \
				t_size *size);
void			draw_overlay1(void *mlx_id, void *win_id, int wx, int wy);
void			draw_overlay2(void *mlx_id, void *win_id, int wx, int wy);
int				rgb_to_hex(t_env *env);
void			draw_fdf(t_env *env);
void			draw_lines(t_env *env);
void			draw_collumns(t_env *env);
void			line(t_env *env);
void			cam_center(t_env *env);
void			color_master(t_env *env);
void			reset_main(t_env *env);
void			reset_status(t_env *env);
void			move_handler(int key, t_env *env);
void			rotation_handler(int key, t_env *env);
void			altitude_handler(int key, t_env *env);
void			esc_handler(t_env *env);
void			color_handler(int key, t_env *env);
void			perspective_handler(t_env *env);
void			theme_handler(t_env *env);
int				error(int code);
char			*itoa_f(int n);
#endif
