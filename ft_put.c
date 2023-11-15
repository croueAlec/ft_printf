/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:28:00 by acroue            #+#    #+#             */
/*   Updated: 2023/11/15 11:39:04 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
