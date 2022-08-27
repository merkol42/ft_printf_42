/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:45:26 by merkol            #+#    #+#             */
/*   Updated: 2022/03/08 14:49:00 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int				ret;
	int				len;
	unsigned int	nb2;
	char			*str;

	ret = 0;
	nb2 = n;
	if (n == 0)
		return (write(1, "0", 1));
	while (nb2 > 0)
	{
		nb2 = nb2 / 10;
		ret++;
	}
	len = ret;
	str = (char *)calloc(1, len);
	while (n > 0)
	{
		str[--len] = (n % 10) + 48;
		n = n / 10;
	}
	ft_putstr(str);
	free (str);
	return (ret);
}

int	ft_len(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n > 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}
