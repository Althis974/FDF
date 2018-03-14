/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 15:14:17 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 12:27:26 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_data(t_env *fdf)
{
	fdf->data.nb_line = 0;
	fdf->data.nb_col = 0;
	fdf->data.x = 0;
	fdf->data.y = 0;
	fdf->data.map = NULL;
	fdf->data.grid = NULL;
	fdf->pt.spc = 0;
	fdf->mlx.new_win = 0;
	fdf->data.max = 0;
	fdf->data.coef = 0;
}

int		ft_error(int kse)
{
	if (kse == 1)
		write(2, "Open Fail.\n", 11);
	else if (kse == 2)
		write(2, "Wrong File.\n", 12);
	else if (kse == 3)
		write(2, "Close Fail.\n", 12);
	return (-1);
}

int		main(int ac, char **av)
{
	t_env	fdf;

	if (ac != 2)
	{
		write(2, "usage : ./fdf <filename>\n", 25);
		return (1);
	}
	ft_bzero(&fdf, sizeof(t_env));
	ft_init_data(&fdf);
	if ((ft_filechecker(av[1], &fdf)) == -1)
		return (-1);
	ft_env_init(&fdf);
	free(&fdf);
	ft_bzero(&fdf, sizeof(t_env));
	return (0);
}
