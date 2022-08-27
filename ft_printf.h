/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:45:25 by merkol            #+#    #+#             */
/*   Updated: 2022/03/09 10:57:37 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_len(unsigned long n, int base);
int		put_nbr2(int n);
int		ft_itoa(int n);
int		ft_putstr(char *str);
int		ft_putnbr_u(unsigned int n);
int		ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_printp(unsigned long a, int format);

#endif
