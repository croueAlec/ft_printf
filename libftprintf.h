/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:07:32 by acroue            #+#    #+#             */
/*   Updated: 2023/11/15 11:44:47 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_isflag(char c);
int		ft_flag_manage(char c, va_list arg);
size_t	ft_printf(const char *format, ...);
void	ft_print_nbr(long n);
int		ft_put_signed(int n);
int		ft_put_unsigned(unsigned int n);
int		ft_put_hex(char *str, int len, int is_address);
int		ft_putnbr_base(long long n, char *base, int is_address);
int	ft_strlen(char *s);

#endif
