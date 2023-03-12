/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:43:52 by apiloian          #+#    #+#             */
/*   Updated: 2023/02/08 16:00:37 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex(unsigned long long dec, const char *fmt)
{
	int	count;

	count = 0;
	if (*fmt == 'x' || *fmt == 'X')
		dec = (unsigned int)dec;
	if (dec >= 16)
	{
		count += hex(dec / 16, fmt);
		hex(dec % 16, fmt);
	}
	else
	{
		if (dec <= 9)
			ft_putchar_fd(dec + '0', 1);
		else
		{
			if (*fmt == 'x' || *fmt == 'p')
				ft_putchar_fd(dec + 'a' - 10, 1);
			else
				ft_putchar_fd(dec + 'A' - 10, 1);
		}
	}
	return (count + 1);
}

int	ft_puts(va_list arg)
{
	const char	*s;

	s = va_arg(arg, const char *);
	if (!s)
	{	
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd((char *)s, 1);
	return (ft_strlen(s));
}

int	ft_putdi(va_list arg)
{
	int		d;
	char	*str;
	size_t	len;

	d = va_arg(arg, int);
	ft_putnbr_fd(d, 1);
	str = ft_itoa(d);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_putu(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n / 10 > 0)
		count = ft_putu(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (count + 1);
}

int	check(const char *fmt, va_list arg)
{
	if (*fmt == '%')
		write(1, fmt, 1);
	else if (*fmt == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (*fmt == 's')
		return (ft_puts(arg));
	else if (*fmt == 'd' || *fmt == 'i')
		return (ft_putdi(arg));
	else if (*fmt == 'u')
		return (ft_putu(va_arg(arg, unsigned int), 1));
	else if (*fmt == 'x' || *fmt == 'X')
		return (hex(va_arg(arg, unsigned int), fmt));
	else if (*fmt == 'p')
	{
		write(1, "0x", 2);
		return (hex(va_arg(arg, unsigned long long), fmt) + 2);
	}
	return (1);
}
