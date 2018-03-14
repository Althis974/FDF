/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putallnbr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 14:46:33 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 14:58:35 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putallnbr(intmax_t n)
{
	if (n == INT64_MIN)
	{
		ft_putchar('-');
		ft_putchar('9');
		ft_putallnbr(223372036854775808);
	}
	else
	{
		if (n < 0)
			if (n != INT64_MIN)
			{
				ft_putchar('-');
				n *= -1;
			}
		if (n < 10)
			ft_putchar(n + '0');
		if (n > 9)
		{
			ft_putallnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
	}
}
