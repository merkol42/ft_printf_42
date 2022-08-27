/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:27:28 by merkol            #+#    #+#             */
/*   Updated: 2022/03/08 16:27:30 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printp(unsigned long a, int format)
{
	unsigned long	i;
	int				j;
	char			*set;
	char			*str;

	set = "0123456789abcdef";
	i = 0;
	if (a == 0)
		return (write(1, "0", 1));
	i = ft_len(a, 16);
	j = i;
	str = malloc(i + 1);
	str[i] = '\0';
	while (a > 0)
	{
		if (format == 'X' && a % 16 > 9)
			str[--i] = set[a % 16] - 32;
		else
			str[--i] = set[a % 16];
		a = a / 16;
	}
	ft_putstr(str);
	free(str);
	return (j);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
