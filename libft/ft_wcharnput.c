/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wcharnput.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/26 16:40:29 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 16:40:31 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcharnput(wchar_t const *s, size_t len, int print)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	res = 0;
	while (s[j] && i <= len)
	{
		if ((i += ft_wcharlen(s[j])) > len)
			break ;
		j++;
	}
	if (print == 1)
		ft_putnwstr(s, j);
	i = 0;
	while (i < j)
	{
		res += ft_wcharlen(s[i]);
		i++;
	}
	return (res);
}
