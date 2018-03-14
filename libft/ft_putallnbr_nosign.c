/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putallnbr_nosign.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 14:45:27 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 14:59:37 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putallnbr_nosign(intmax_t n)
{
	if (n == INT64_MIN)
	{
		ft_putchar('9');
		ft_putallnbr(223372036854775808);
	}
	else
	{
		if (n < 0)
			if (n != INT64_MIN)
				n *= -1;
		if (n < 10)
			ft_putchar(n + '0');
		if (n > 9)
		{
			ft_putallnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
}
