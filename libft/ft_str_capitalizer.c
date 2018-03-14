/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_capitalizer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 13:26:29 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 13:53:48 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_min(char *s, int *index, int *first)
{
	int i;

	i = *index;
	s[i] -= 32;
	*first = 1;
	*index += 1;
}

void		ft_str_capitalizer(char *s)
{
	int i;
	int first;

	i = 0;
	while (s[i] != '\0')
	{
		first = 0;
		while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
			i++;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
		{
			if (s[i] >= 97 && s[i] <= 122 && first == 0)
				ft_min(s, &i, &first);
			else if (s[i] >= 65 && s[i] <= 90 && first == 0)
			{
				first = 1;
				i++;
			}
			else
				first = 1;
			if (s[i] >= 65 && s[i] <= 90 && first == 1)
				s[i] += 32;
			i++;
		}
	}
}
