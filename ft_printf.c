/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:07:54 by merkol            #+#    #+#             */
/*   Updated: 2022/03/09 10:30:00 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int a, int format)
{
	int				i;
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

int	print_p(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	i += 2;
	i += ft_printp(nb, 1);
	return (i);
}

int	ft_format(va_list ap, const char format)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (format == 'p')
		ret += print_p(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		ret += put_nbr2(va_arg(ap, int));
	else if (format == 'u')
		ret += ft_putnbr_u(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		ret += ft_hexa(va_arg(ap, unsigned long), format);
	if (format == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ret += ft_format(ap, str[++i]);
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
