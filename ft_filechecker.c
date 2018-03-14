/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filechecker.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 14:03:43 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 13:07:50 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		ft_filechecker(char *file, t_env *fdf)
{
	if ((ft_check_format(file, fdf)) == -1)
		return (-1);
	if ((ft_map_alloc(file, fdf)) == -1)
		return (-1);
	if (ft_check_line(fdf) == -1)
		return (-1);
	if ((ft_fulfill_grid(fdf)) == -1)
		return (-1);
	return (0);
}

int		ft_check_format(char *file, t_env *fdf)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = (open(file, O_RDONLY))) == -1)
		return (ft_error(1));
	ret = get_next_line(fd, &line);
	free(line);
	if ((ret == 0) || (ret == -1))
		return (ft_error(2));
	fdf->data.nb_line++;
	while (get_next_line(fd, &line))
	{
		fdf->data.nb_line++;
		free(line);
	}
	if ((close(fd)) == -1)
		return (ft_error(3));
	return (0);
}

int		ft_map_alloc(char *file, t_env *fdf)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 1;
	line = NULL;
	if ((fdf->data.map = (char**)malloc(sizeof(char*)
					* (fdf->data.nb_line + 1))) == NULL)
		return (-1);
	fd = (open(file, O_RDONLY));
	ret = get_next_line(fd, &line);
	fdf->data.map[0] = line;
	while (get_next_line(fd, &line))
	{
		fdf->data.map[i] = line;
		i++;
	}
	fdf->data.map[i] = NULL;
	close(fd);
	return (0);
}

int		ft_check_line(t_env *fdf)
{
	int		i;

	fdf->data.nb_col = ft_word_count(fdf->data.map[0], ' ');
	i = 1;
	while (fdf->data.map[i])
	{
		if (fdf->data.nb_col != ft_word_count(fdf->data.map[i], ' '))
		{
			write(2, "Erroneous data.\n", 16);
			i = 0;
			while (fdf->data.map[i])
			{
				free(fdf->data.map[i]);
				i++;
			}
			free(fdf->data.map);
			return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_fulfill_grid(t_env *fdf)
{
	int		i;
	char	**split;

	if (!(fdf->data.grid = ft_tab2d_init(fdf->data.nb_line, fdf->data.nb_col)))
		return (-1);
	i = -1;
	while (fdf->data.map[++i])
	{
		fdf->data.x = 0;
		split = ft_strsplit(fdf->data.map[i], ' ');
		while (split[fdf->data.x] != NULL)
		{
			fdf->data.grid[fdf->data.y][fdf->data.x] =
				ft_atoi(split[fdf->data.x]);
			if (fdf->data.max < fdf->data.grid[fdf->data.y][fdf->data.x])
				fdf->data.max = fdf->data.grid[fdf->data.y][fdf->data.x];
			free(split[fdf->data.x]);
			fdf->data.x++;
		}
		free(split);
		free(fdf->data.map[i]);
		fdf->data.y++;
	}
	free(fdf->data.map);
	return (0);
}
