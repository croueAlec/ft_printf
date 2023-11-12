/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:07:32 by acroue            #+#    #+#             */
/*   Updated: 2023/11/12 18:14:16 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf
{
	char			*content;
	size_t			*length;
	struct s_printf	*next;
}	t_printf;

int	ft_printf(const char *format, ...);

#endif
