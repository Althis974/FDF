/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/05 17:02:23 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 17:02:03 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		ft_env_init(t_env *fdf)
{
	fdf->mlx.mlx_ptr = mlx_init();
	ft_win_size(fdf);
	ft_spacing(fdf);
	ft_tools(fdf);
	if (!fdf->mlx.new_win)
	{
		fdf->mlx.new_win = 1;
		fdf->mlx.win = mlx_new_window(fdf->mlx.mlx_ptr, fdf->mlx.win_len,
				fdf->mlx.win_wid, "FDF");
		mlx_key_hook(fdf->mlx.win, ft_getting_keys, fdf);
		mlx_expose_hook(fdf->mlx.win, ft_create, fdf);
		mlx_loop(fdf->mlx.mlx_ptr);
	}
	return (0);
}

void	ft_win_size(t_env *fdf)
{
	if (fdf->data.nb_col <= 30)
		fdf->mlx.win_len = fdf->data.nb_col * 75;
	else if (fdf->data.nb_col <= 50)
		fdf->mlx.win_len = fdf->data.nb_col * 50;
	else if (fdf->data.nb_col <= 70)
		fdf->mlx.win_len = fdf->data.nb_col * 25;
	else if (fdf->data.nb_col <= 120)
		fdf->mlx.win_len = fdf->data.nb_col * 10;
	else
		fdf->mlx.win_len = MAX_LEN;
	if (fdf->data.nb_line <= 30)
		fdf->mlx.win_wid = fdf->data.nb_line * 75;
	else if (fdf->data.nb_line <= 50)
		fdf->mlx.win_wid = fdf->data.nb_line * 50;
	else if (fdf->data.nb_line <= 70)
		fdf->mlx.win_wid = fdf->data.nb_line * 25;
	else if (fdf->data.nb_line <= 120)
		fdf->mlx.win_wid = fdf->data.nb_line * 10;
	else
		fdf->mlx.win_wid = MAX_WID;
}

void	ft_spacing(t_env *fdf)
{
	if (fdf->data.nb_col <= 10)
		fdf->pt.spc = 30;
	else if (fdf->data.nb_col <= 30)
		fdf->pt.spc = 25;
	else if (fdf->data.nb_col <= 50)
		fdf->pt.spc = 20;
	else if (fdf->data.nb_col <= 100)
		fdf->pt.spc = 10;
	else
		fdf->pt.spc = 5;
}

void	ft_tools(t_env *fdf)
{
	fdf->pt.pos = 1;
	if (fdf->mlx.win_len == MAX_LEN && fdf->mlx.win_wid == MAX_WID)
	{
		fdf->moove_h = (float)fdf->mlx.win_len / 2;
		fdf->moove_v = (float)fdf->mlx.win_wid / 15;
	}
	else
	{
		fdf->moove_h = (float)fdf->mlx.win_len / 2.1;
		fdf->moove_v = (float)fdf->mlx.win_wid / 2.5;
	}
	fdf->pt.col.red = 255;
	fdf->pt.col.green = 255;
	fdf->pt.col.blue = 255;
	fdf->pt.col.grad = 0;
}

int		ft_create(t_env *fdf)
{
	fdf->mlx.img.img_ptr = mlx_new_image(fdf->mlx.mlx_ptr, fdf->mlx.win_len,
			fdf->mlx.win_wid);
	fdf->mlx.img.data = mlx_get_data_addr(fdf->mlx.img.img_ptr,
			&fdf->mlx.img.bpp, &fdf->mlx.img.size_l, &fdf->mlx.img.endian);
	ft_trace(fdf);
	mlx_put_image_to_window(fdf->mlx.mlx_ptr, fdf->mlx.win,
			fdf->mlx.img.img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx.mlx_ptr, fdf->mlx.img.img_ptr);
	return (0);
}
