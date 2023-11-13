/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:14:53 by acroue            #+#    #+#             */
/*   Updated: 2023/11/13 14:55:57 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int	ft_printf(const char *format, ...)
// {
	
// }

#include <stdio.h>

int	ft_isflag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

int	ft_isparam(char c, char *params)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (c == params[i])
		{
			return (1);
		}
	}
	return (0);
}

void	ft_flag_manager(t_flags_m *flag, char c)
{
	flag->space = 0;
	flag->sign = 0;
	flag->justify = 0;
	flag->zero_padding = 0;
	flag->hashtag = 0;
	if (c == ' ')
		flag->space = 1;
	if (c == '+')
		flag->sign = 1;
	if (c == '-')
		flag->justify = 1;
	if (c == '0')
		flag->zero_padding = 1;
	if (c == '#')
		flag->hashtag = 1;
}

char	*ft_check_flag(char *format)
{
	size_t		i;
	t_flags_m	*flag;

	flag = malloc(sizeof(t_flags_m));
	if (!flag)
		return (0);
	i = 0;
	while (!ft_isflag(format[i]) && !(format[i] >= '1' && format[i] <= '9') && format[i])
	{
		if (ft_isparam(format[i], " +-0#"))
			ft_flag_manager(flag, format[i]);
		i++;
	}
	printf("%d\n%d\n%d\n%d\n%d\n", flag->space, flag->sign, flag->justify, flag->zero_padding, flag->hashtag);

	free(flag);

	// // creer node avec node_length puis node_length = 0
	// if (format[i + 1] == '%')
	// 	i++; // ajouter une node %
	// else if (ft_isflag(format[i + 1]))
	// {
	// 	i++; // ajouter une node correspondante ?
	// }
	// else
	// 	return (0); // % suivi d'un mauvais flag

	return ("salut");
}

size_t	ft_count_flags(char *format)
{
	size_t	i;
	size_t	length;
	size_t	node_length;

	i = 0;
	length = 0;
	node_length = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_check_flag(&format[i + 1]);
		}
		i++;
		length++;
		node_length++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_check_flag(argv[1]);
	return (0);
}
