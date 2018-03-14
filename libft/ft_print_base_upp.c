/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_base_upp.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 12:11:14 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 16:46:21 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_base_upp(uintmax_t n, uintmax_t base)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= base)
		ft_print_base_upp(n / base, base);
	ft_putchar(hexa[n % base]);
}
