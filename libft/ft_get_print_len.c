/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_print_len.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 10:10:42 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 17:04:45 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_print_len(uintmax_t n, uintmax_t base, size_t *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (*len == 0)
		*len += 1;
	if (n >= base)
	{
		*len += 1;
		ft_get_print_len(n / base, base, len);
	}
}
