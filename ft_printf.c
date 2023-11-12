/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:14:53 by acroue            #+#    #+#             */
/*   Updated: 2023/11/12 18:48:26 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	
}

int	ft_is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X')
		return (1);
	else
		return (0);
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
			creer node avec node_length puis node_length = 0
			if (format[i + 1] == '%')
				i++; // ajouter une node %
			else if (ft_is_flag(format[i + 1]))
			{
				i++; // ajouter une node correspondante ?
			}
			else
				return (0); // % suivi d'un mauvais flag
		}
		i++;
		length++;
		node_length++;
	}
	
}
