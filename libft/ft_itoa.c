/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:12:14 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 13:58:15 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int nbr)
{
	char	*res;
	int		val;
	int		len;
	int		i;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	val = ft_abs(nbr);
	len = get_len(val);
	if (nbr < 0)
		len++;
	if ((res = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i++ < len)
	{
		res[len - i] = val % 10 + '0';
		val /= 10;
	}
	if (nbr < 0)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}
