/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:07 by apiloian          #+#    #+#             */
/*   Updated: 2023/02/02 19:31:32 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(const char *fmt, va_list arg, int state, int len)
{
	while (*fmt)
	{
		if (state == 0)
		{
			if (*fmt == '%')
			{
				state = 1;
				len--;
			}
			else
				write(1, &*fmt, 1);
			len++;
		}
		else
		{
			len += check(fmt, arg);
			state = 0;
		}
		fmt++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)	
{
	va_list	arg;
	int		len;

	va_start(arg, fmt);
	len = ft_print(fmt, arg, 0, 0);
	va_end(arg);
	return (len);
}

int main()
{
	ft_printf("%");
}