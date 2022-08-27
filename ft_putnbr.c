/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:36:10 by merkol            #+#    #+#             */
/*   Updated: 2022/03/08 16:24:02 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}

int	put_nbr2(int nb)
{
	int	i;
	int	nb2;

	i = 0;
	nb2 = nb;
	if (nb == 0)
		i = 1;
	if (nb2 == -2147483648)
		i = 11;
	else if (nb2 < 0)
	{
		nb2 *= -1;
		i++;
	}
	while (nb2 > 0)
	{
		nb2 = nb2 / 10;
		i++;
	}
	ft_putnbr(nb);
	return (i);
}
