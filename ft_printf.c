/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:32:51 by rluiz             #+#    #+#             */
/*   Updated: 2023/12/09 19:33:50 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdarg.h>

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return ;
}

void	ft_putnbr_base(unsigned int nb, char *base, unsigned int size)
{
	if (nb >= size)
		ft_putnbr_base(nb / size, base, size);
	ft_putchar(base[nb % size]);
	return ;
}

void	ft_pourcent(const char *src, va_list list, int i)
{
	if (src[i] == 's')
		ft_putstr(va_arg(list, char *));
	else if (src[i] == 'd')
		ft_putnbr(va_arg(list, int));
	return ;
}

int	ft_printf(t_arena, const char *src, ...)
{
	int		i;
	va_list	list;

	i = -1;
	va_start(list, src);
	while (src[++i])
	{
		if (src[i] == '%')
			ft_pourcent(src, list, ++i);
		else
			ft_putchar(src[i]);
	}
	va_end(list);
	return (0);
}