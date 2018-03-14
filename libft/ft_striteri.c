/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_striteri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 09:21:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 09:21:22 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			i;
	size_t			len;
	unsigned int	j;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(j, &s[j]);
		j++;
		i++;
	}
}
