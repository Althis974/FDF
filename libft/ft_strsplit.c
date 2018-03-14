/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 09:24:32 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 15:38:01 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i] != '\0' && c != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	word_size(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (!s || !(res = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1))))
		return (NULL);
	res[word_count(s, c)] = NULL;
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			return (res);
		i = 0;
		if (!(res[j] = (char *)malloc(sizeof(char) * (word_size(s, c) + 1))))
			return (NULL);
		while (*s != c && *s)
			res[j][i++] = *s++;
		res[j++][i] = '\0';
	}
	return (res);
}
