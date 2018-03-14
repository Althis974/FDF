/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gradient.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 10:19:43 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 13:01:04 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_gradient(t_env *fdf, int x, int y)
{
	fdf->data.coef = fdf->data.max > 0 ?
		((float)fdf->pt.pos * (fdf->data.grid[fdf->data.y][fdf->data.x]))
		/ (float)fdf->data.max : 0;
	fdf->data.coef = fdf->data.coef < 0 ? -fdf->data.coef : fdf->data.coef;
	fdf->pt.col.red = (255 - 169) * fdf->data.coef + 169;
	fdf->pt.col.green = (255 - 247) * fdf->data.coef + 247;
	fdf->pt.col.blue = (255 - 253) * fdf->data.coef + 253;
	fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
		+ (y * fdf->mlx.img.size_l)] = fdf->pt.col.red;
	fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
		+ (y * fdf->mlx.img.size_l) + 1] = fdf->pt.col.green;
	fdf->mlx.img.data[(x * (fdf->mlx.img.bpp / 8))
		+ (y * fdf->mlx.img.size_l) + 2] = fdf->pt.col.blue;
}

void	ft_get_back(t_env *fdf)
{
	fdf->pt.col.grad = 0;
	fdf->pt.col.red = 255;
	fdf->pt.col.green = 255;
	fdf->pt.col.blue = 255;
}
