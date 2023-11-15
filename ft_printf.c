/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:14:53 by acroue            #+#    #+#             */
/*   Updated: 2023/11/15 11:40:21 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_isflag(char c)
{
	if (c == 'c' || c == 's' || c == '%')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == 'p')
		return (1);
	else
		return (0);
}

int	ft_flag_manage(char c, va_list arg)
{
	if (c == '%')
		return (ft_putchar(37));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_put_signed(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_put_unsigned(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(arg, long long), "0123456789abcdef", 0));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(arg, long long), "0123456789ABCDEF", 0));
	else if (c == 'p')
		return (ft_putnbr_base(va_arg(arg, long long), "0123456789abcdef", 2));
	else
		return (write(1, "you are not supposed to see this", 32));
}

size_t	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	length;
	va_list	arg;

	i = 0;
	length = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_isflag(format[i + 1]))
		{
			i++;
			length += ft_flag_manage(format[i], arg);
		}
		else
		{
			ft_putchar(format[i]);
			length++;
		}
		i++;
	}
	va_end(arg);
	return (length);
}
