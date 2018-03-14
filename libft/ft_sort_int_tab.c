/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_int_tab.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 09:55:24 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 09:55:26 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int len;

	i = 0;
	j = 1;
	len = 0;
	while (len < size)
	{
		while (j < size)
		{
			if (tab[i] < tab[j])
				ft_swap(&tab[i], &tab[j], sizeof(int));
			j++;
		}
		i++;
		len++;
		j = 0;
	}
}
