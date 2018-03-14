/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_keycode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 16:34:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 12:52:27 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getting_keys(int key, t_env *fdf)
{
	if (key == ESC)
		exit(0);
	else if (key == F5)
		ft_env_init(fdf);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN
			|| key == A || key == D || key == W || key == S)
		ft_moove(key, fdf);
	else if (key == I || key == O)
		ft_zoom(key, fdf);
	else if (key == LESS || key == MORE)
		ft_altitude(key, fdf);
	else if (key == R || key == G || key == B)
		ft_color(key, fdf);
	else if (key == F1)
		fdf->pt.col.grad = 1;
	else if (key == F2)
		fdf->pt.col.grad = 2;
	else if (key == F3)
		ft_get_back(fdf);
	ft_create(fdf);
	return (0);
}

void	ft_moove(int key, t_env *fdf)
{
	if (key == LEFT || key == A)
		if ((fdf->moove_h -= 25) - (fdf->pt.spc * (fdf->data.nb_line - 1)
					* 0.5) < 0)
			fdf->moove_h += 25;
	if (key == RIGHT || key == D)
		if ((fdf->moove_h += 25) + (fdf->pt.spc * (fdf->data.nb_col - 1)
					* 0.5) > fdf->mlx.win_len)
			fdf->moove_h -= 25;
	if (key == UP || key == W)
		if ((fdf->moove_v -= 25) - (fdf->pt.spc * 0.5) < 0)
			fdf->moove_v += 25;
	if (key == DOWN || key == S)
		if ((fdf->moove_v += 25) + (fdf->pt.spc * ((fdf->data.nb_col - 1 +
			fdf->data.nb_line - 1) / 1.9) * 0.5) > fdf->mlx.win_wid)
			fdf->moove_v -= 25;
}

void	ft_zoom(int key, t_env *fdf)
{
	if (key == O)
	{
		fdf->pt.spc -= 5;
		if (fdf->pt.spc <= 0)
			fdf->pt.spc += 5;
	}
	else if (key == I)
		fdf->pt.spc += 5;
}

void	ft_altitude(int key, t_env *fdf)
{
	if (key == MORE)
		fdf->pt.pos -= 5;
	else if (key == LESS)
		fdf->pt.pos += 5;
}

void	ft_color(int key, t_env *fdf)
{
	if (key == R)
		fdf->pt.col.red -= 25;
	else if (key == G)
		fdf->pt.col.green -= 25;
	else if (key == B)
		fdf->pt.col.blue -= 25;
}
