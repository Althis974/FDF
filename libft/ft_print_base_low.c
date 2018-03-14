/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_base_low.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 12:11:40 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 16:46:11 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_base_low(uintmax_t n, uintmax_t base)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= base)
		ft_print_base_low(n / base, base);
	ft_putchar(hexa[n % base]);
}
