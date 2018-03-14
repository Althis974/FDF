/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 17:05:52 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 16:41:51 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int value, int base)
{
	char	*res;
	int		val;
	int		len;
	char	*hex;
	int		i;

	hex = "0123456789ABCDEF";
	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	val = ft_abs(value);
	len = ft_get_len(val, base);
	if (value < 0 && base == 10)
		len++;
	if ((res = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i++ < len)
	{
		res[len - i] = hex[val % base];
		val /= base;
	}
	if (value < 0 && base == 10)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}
