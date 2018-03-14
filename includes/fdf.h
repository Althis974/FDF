/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 15:20:39 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 16:58:11 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "keycode.h"
# define MAX_LEN 2560
# define MAX_WID 1440

typedef struct	s_data
{
	char		**map;
	int			**grid;
	int			x;
	int			y;
	int			max;
	int			coef;
	int			nb_line;
	int			nb_col;
}				t_data;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	size_t		win_wid;
	size_t		win_len;
	int			new_win;
	t_img		img;
}				t_mlx;

typedef struct	s_col
{
	int			red;
	int			green;
	int			blue;
	int			grad;
}				t_col;

typedef struct	s_pt
{
	int			x;
	int			y;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	int			spc;
	int			pos;
	t_col		col;
}				t_pt;

typedef struct	s_env
{
	t_data		data;
	t_pt		pt;
	t_mlx		mlx;
	int			moove_h;
	int			moove_v;
}				t_env;

/*
**	Check file and fill map if corrects.
*/

int				ft_filechecker(char *file, t_env *fdf);
int				ft_check_format(char *file, t_env *fdf);
int				ft_map_alloc(char *file, t_env *fdf);
int				ft_check_line(t_env *fdf);
int				ft_fulfill_grid(t_env *fdf);
int				ft_error(int kse);
/*
**	Initialize environment.
*/

int				ft_env_init(t_env *fdf);
void			ft_win_size(t_env *fdf);
void			ft_spacing(t_env *fdf);
void			ft_tools(t_env *fdf);
int				ft_create(t_env *fdf);

/*
**	Functions that take care of tracing.
*/

void			ft_trace(t_env *fdf);
void			ft_bresenham(t_env *fdf);
void			ft_set_pixel(t_env *fdf, int x, int y);
void			ft_set_col(t_env *fdf);
void			ft_set_line(t_env *fdf);
void			ft_set_col_pt1(t_env *fdf);
void			ft_set_col_pt2(t_env *fdf);
void			ft_set_line_pt1(t_env *fdf);
void			ft_set_line_pt2(t_env *fdf);

/*
**	Functions that take care of events.
*/

int				ft_getting_keys(int key, t_env *fdf);
void			ft_moove(int key, t_env *fdf);
void			ft_zoom(int key, t_env *fdf);
void			ft_altitude(int key, t_env *fdf);
void			ft_color(int key, t_env *fdf);
void			ft_gradient(t_env *fdf, int x, int y);
void			ft_get_back(t_env *fdf);

#endif
