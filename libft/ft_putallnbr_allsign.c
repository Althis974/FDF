/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putallnbr_allsign.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 14:46:40 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 15:00:56 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_check_int_max(intmax_t n)
{
	if (n == INT64_MIN)
	{
		ft_putchar('-');
		ft_putchar('9');
		ft_putallnbr(223372036854775808);
	}
}

void			ft_putallnbr_allsign(intmax_t n)
{
	int sign;

	sign = 0;
	ft_check_int_max(n);
	if (n < 0 && sign != 1)
		if (n != INT64_MIN)
		{
			ft_putchar('-');
			n *= -1;
			sign = 1;
		}
	if (n >= 0 && sign != 1)
	{
		ft_putchar('+');
		sign = 1;
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putallnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
