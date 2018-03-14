/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line3.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 13:45:35 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/12 17:09:28 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate and store in tmp the concat of buf and tab
*/

static char	*ft_memcat(char *buf, char *tab)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (buf)
		i = ft_strlen(buf);
	if (tab)
		j = ft_strlen(tab);
	if ((tmp = (char*)malloc(sizeof(char) * (i + j + 1))) == NULL)
		return (NULL);
	ft_memcpy(tmp, buf, i);
	ft_memcpy(tmp + i, tab, j);
	tmp[i + j] = '\0';
	free(buf);
	return (tmp);
}

/*
** Search for EOL and returns its index if it's found
** returns -1 else
*/

static int	ft_find_endline(char *buf)
{
	int	eol;

	eol = 0;
	while (buf[eol] != '\n' && buf[eol])
		eol++;
	if (buf[eol] == '\n')
	{
		buf[eol] = '\0';
		return (eol);
	}
	else
		return (-1);
}

/*
** Check the current read line in buf and store it in $line according to cond
*/

static int	ft_check(char **buf, char **tab, char **line)
{
	char	*tmp;
	int		eol;

	*buf = ft_memcat(*buf, *tab);
	eol = ft_find_endline(*buf);
	if (eol > -1)
	{
		*line = ft_strdup(*buf);
		tmp = *buf;
		*buf = ft_strdup(*buf + eol + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

/*
** Store in tmp what will be read according to cond and BUFF_SIZE
** buff[fd] enable to read on multi fd
*/

int			ft_normalize(char **tmp, int kse, char **buf)
{
	if (kse == 1)
	{
		ft_strdel(buf);
		free(*tmp);
	}
	else if (kse == 2)
		free(*tmp);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	int			res;
	int			ret;
	char		*tmp;
	static char *buf[BUFF_SIZE + 1];

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		res = ft_check(&buf[fd], &tmp, line);
		free(tmp);
		if (res == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((res = ft_check(&buf[fd], &tmp, line)))
		return (ft_normalize(&tmp, 2, &buf[fd]));
	else if (ft_strlen(buf[fd]) > 0)
	{
		*line = ft_strdup(buf[fd]);
		return (ft_normalize(&tmp, 1, &buf[fd]));
	}
	free(tmp);
	return (res);
}
