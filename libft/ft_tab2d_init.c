/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tab2d_init.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 12:15:25 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/13 12:15:38 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		**ft_tab2d_init(size_t y, size_t x)
{
	size_t	i;
	int		**tab;
	int		*tab2;

	i = 0;
	if (!(tab = (int**)malloc(sizeof(tab) * y)))
		return (NULL);
	if (!(tab2 = (int*)malloc(sizeof(tab2) * (x * y))))
		return (NULL);
	while (i < y)
	{
		tab[i] = &tab2[i * x];
		i++;
	}
	return (tab);
}
