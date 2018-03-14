/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_len_sign.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 12:08:04 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 14:52:38 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len_sign(intmax_t val, int base)
{
	int len;

	len = 2;
	val = ft_abs(val);
	while (val /= base)
		len++;
	return (len);
}
