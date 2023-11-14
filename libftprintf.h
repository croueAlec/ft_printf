/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:07:32 by acroue            #+#    #+#             */
/*   Updated: 2023/11/14 09:33:18 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_print
{
	char			*content;
	size_t			*length;
	void			*next;
}	t_print;

typedef struct s_flags_manage
{
	char	space;
	char	sign;
	char	justify;
	char	zero_padding;
	char	hashtag;

}	t_flags_m;

// int	ft_printf(const char *format, ...);


#endif
