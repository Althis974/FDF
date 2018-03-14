/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trace.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 10:13:35 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 11:18:29 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_trace(t_env *fdf)
{
	ft_set_col(fdf);
	ft_set_line(fdf);
}

void	ft_bresenham(t_env *fdf)
{
	fdf->pt.dx = (abs(fdf->pt.x2 - fdf->pt.x1));
	fdf->pt.dy = (abs(fdf->pt.y2 - fdf->pt.y1));
	fdf->pt.sx = (fdf->pt.x1 < fdf->pt.x2 ? 1 : -1);
	fdf->pt.sy = (fdf->pt.y1 < fdf->pt.y2 ? 1 : -1);
	fdf->pt.err = (fdf->pt.dx > fdf->pt.dy ? fdf->pt.dx : -fdf->pt.dy) / 2;
	while (101)
	{
		ft_set_pixel(fdf, fdf->moove_h + fdf->pt.x1,
				fdf->moove_v + fdf->pt.y1);
		if (fdf->pt.x1 == fdf->pt.x2 && fdf->pt.y1 == fdf->pt.y2)
			break ;
		fdf->pt.e2 = fdf->pt.err;
		if (fdf->pt.e2 > -fdf->pt.dx)
		{
			fdf->pt.err -= fdf->pt.dy;
			fdf->pt.x1 += fdf->pt.sx;
		}
		if (fdf->pt.e2 < fdf->pt.dy)
		{
			fdf->pt.err += fdf->pt.dx;
			fdf->pt.y1 += fdf->pt.sy;
		}
	}
}

void	ft_set_col(t_env *fdf)
{
	fdf->data.x = 0;
	fdf->pt.x = 0;
	while (fdf->pt.x < fdf->data.nb_col * fdf->pt.spc)
	{
		fdf->pt.y = 0;
		fdf->data.y = 0;
		ft_set_col_pt1(fdf);
		while (fdf->pt.y < ((fdf->data.nb_line - 1) * fdf->pt.spc))
		{
			ft_set_col_pt2(fdf);
			ft_bresenham(fdf);
			fdf->data.y++;
			fdf->pt.y += fdf->pt.spc;
			fdf->pt.x1 = fdf->pt.x2;
			fdf->pt.y1 = fdf->pt.y2;
		}
		fdf->data.x++;
		fdf->pt.x += fdf->pt.spc;
	}
}

void	ft_set_line(t_env *fdf)
{
	fdf->data.y = 0;
	fdf->pt.y = 0;
	while (fdf->pt.y < fdf->data.nb_line * fdf->pt.spc)
	{
		fdf->data.x = 0;
		fdf->pt.x = 0;
		ft_set_line_pt1(fdf);
		while (fdf->pt.x < (fdf->data.nb_col - 1) * fdf->pt.spc)
		{
			ft_set_line_pt2(fdf);
			ft_bresenham(fdf);
			fdf->data.x++;
			fdf->pt.x += fdf->pt.spc;
			fdf->pt.x1 = fdf->pt.x2;
			fdf->pt.y1 = fdf->pt.y2;
		}
		fdf->data.y++;
		fdf->pt.y += fdf->pt.spc;
	}
}
