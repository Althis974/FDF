/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 12:29:24 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 13:07:54 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pixel(t_env *fdf, int x, int y)
{
	if (x > 0 && y > 0 && x < (ssize_t)fdf->mlx.win_len
			&& y < (ssize_t)fdf->mlx.win_wid)
	{
		if (!fdf->pt.col.grad)
		{
			fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
				+ (y * fdf->mlx.img.size_l)] = fdf->pt.col.red;
			fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
				+ (y * fdf->mlx.img.size_l) + 1] = fdf->pt.col.green;
			fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
				+ (y * fdf->mlx.img.size_l) + 2] = fdf->pt.col.blue;
		}
		else if (fdf->pt.col.grad == 1)
		{
			fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
				+ (y * fdf->mlx.img.size_l)] = fdf->pt.col.red - x;
			fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
				+ (y * fdf->mlx.img.size_l) + 1] = fdf->pt.col.green - y;
			fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
				+ (y * fdf->mlx.img.size_l) + 2] = fdf->pt.col.blue - (x + y);
		}
		else if (fdf->pt.col.grad == 2)
			ft_gradient(fdf, x, y);
	}
}

void	ft_set_col_pt1(t_env *fdf)
{
	fdf->pt.x1 = 0.5 * fdf->pt.x - 0.5 * fdf->pt.y;
	fdf->pt.y1 = (fdf->pt.pos * (fdf->data.grid[fdf->data.y][fdf->data.x]))
		+ (0.5 / 2) * fdf->pt.x + (0.5 / 2) * fdf->pt.y;
}

void	ft_set_col_pt2(t_env *fdf)
{
	fdf->pt.x2 = 0.5 * fdf->pt.x - 0.5 * (fdf->pt.y + fdf->pt.spc);
	fdf->pt.y2 = (fdf->pt.pos * (fdf->data.grid[fdf->data.y + 1][fdf->data.x]))
		+ (0.5 / 2) * fdf->pt.x + (0.5 / 2) * (fdf->pt.y + fdf->pt.spc);
}

void	ft_set_line_pt1(t_env *fdf)
{
	fdf->pt.x1 = 0.5 * fdf->pt.x - 0.5 * fdf->pt.y;
	fdf->pt.y1 = (fdf->pt.pos * (fdf->data.grid[fdf->data.y][fdf->data.x]))
		+ (0.5 / 2) * fdf->pt.x + (0.5 / 2) * fdf->pt.y;
}

void	ft_set_line_pt2(t_env *fdf)
{
	fdf->pt.x2 = 0.5 * (fdf->pt.x + fdf->pt.spc) - 0.5 * fdf->pt.y;
	fdf->pt.y2 = (fdf->pt.pos * (fdf->data.grid[fdf->data.y][fdf->data.x + 1]))
		+ (0.5 / 2) * fdf->pt.x + (0.5 / 2) * (fdf->pt.y + fdf->pt.spc);
}
