/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:14:53 by acroue            #+#    #+#             */
/*   Updated: 2023/11/15 11:02:58 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

#include <stdio.h>

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

void	ft_print_nbr(long n)
{
	char	c;

	c = n % 10 + 48;
	if (n >= 10)
	{
		ft_print_nbr(n / 10);
	}
	write(1, &c, 1);
}

int	ft_put_signed(int n)
{
	int	length;
	int	temp;
	
	temp = 0;
	length = 1;
	write(1, "-", n < 0);
	if (n == -2147483648)
		return (write(1, "2147483648", 10) + 1);
	else if (n < 0)
	{
		length++;
		n *= -1;
	}
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		length++;
	}
	ft_print_nbr(n);
	// printf("\n\tLEN = %d\n", length);
	return (length);
}

int	ft_put_unsigned(unsigned int n)
{
	unsigned int	temp;
	size_t			length;
	
	temp = n;
	length = 1;
	while (temp >= 10)
	{
		temp /= 10;
		length++;
	}
	ft_print_nbr(n);
	// printf("\n\tLEN = %zu\n", length);
	return (length);
}

int	ft_put_hex(char *str, int len, int is_address)
{
	size_t	length;

	length = 0;
	if (is_address == 2)
		length += write(1, "0x", 2);
	else if (is_address == 1)
		length += write(1, "-", 1);
	while (len--)
		length += write(1, &str[len], 1);
	free(str);
	return (length);
}

int	ft_putnbr_base(long long n, char *base, int is_address)
{
	int		b_length;
	size_t	i;
	char	*str;

	if (is_address == 2)
		n = (unsigned long long)n;
	b_length = ft_strlen(base);
	str = malloc((b_length + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		is_address = 1;
	}
	while (n > 0)
	{
		str[i] = base[n % b_length];
		n /= b_length;
		i++;
	}
	str[i] = '\0';
	return (ft_put_hex(str, i, is_address));
}

int	ft_flag_manage(char c, va_list arg)
{
	if (c == '%')
		return (ft_putchar(37));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char*)));
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

int	main(int argc, char *argv[])
{
	int	a;
	int	b;
	printf("%d\t%s\n",argc ,argv[0]);
	a = ft_printf("salut %% %c %s %x %X %p %d %i %u\n", 'D', "SALUT", -0xee, -0xee, -0xee);
	b = printf("salut %% %c %s hex hex pointer %d %i %u\n", 'D', "SALUT", -0xee, -0xee, -0xee);

	printf("\n%d\t%d\n", a, b);

	a = ft_printf("%d %i %u\n", -0xee, -0xee, -0xee);
	b = printf("%d %i %u\n", -0xee, -0xee, -0xee);

	printf("\n%d\t%d\n", a, b);
	return (0);
}

// ./a.out "salut %% %c %s %x %X %p %d %i %u"
