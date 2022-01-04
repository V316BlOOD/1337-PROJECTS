/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hl_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:22:44 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/24 22:02:19 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_flags g_f;

int				print_format(va_list *st, const char format, char *s)
{
	int len;

	len = 0;
	if (format == 'i' || format == 'd')
		len = print_int(s, st);
	else if (format == 'c')
		len = print_char(s, st);
	else if (format == 's')
		len = print_string(s, st);
	else if (format == 'u')
		len = print_uint(s, st);
	else if (format == 'x' || format == 'X')
		len = print_hex(s, st, format == 'x' ? 0 : 1);
	else if (format == 'p')
		len = print_pointer(s, st);
	else if (format == '%')
		len = print_percentage(s, st);
	return (len);
}

void			my_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_putunbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		my_putchar(n % 10 + '0');
	}
	if (n < 10)
		my_putchar(n % 10 + '0');
	return (n);
}

int				reducer(char *s, int *spaces, int value, int p)
{
	int zeroes;

	zeroes = 0;
	if (s[1] == '0' && is_point(s + 1) && g_f.p < 0 && g_f.z < 0)
		*spaces = g_f.z;
	else if (is_point(s + 1) && g_f.p >= 0 && s[1] != '0')
		*spaces = g_f.s;
	else if (s[1] == '0' && is_point(s + 1) && g_f.p >= 0)
		*spaces = g_f.z;
	else if (s[1] != '0')
		*spaces = g_f.s;
	else if (s[1] == '0' && !is_point(s + 1) && g_f.z < 0)
		*spaces = g_f.z;
	if (is_point(s + 1) && g_f.p > 0)
		zeroes = g_f.p;
	else if (is_point(s + 1) && g_f.p < 0 && g_f.z >= 0)
		zeroes = g_f.z - (value < 0 ? 1 : 0) - (p ? 2 : 0);
	else if (!is_point(s + 1) && s[1] == '0' && g_f.z >= 0)
		zeroes = g_f.z - (value < 0 ? 1 : 0) - (p ? 2 : 0);
	return (zeroes);
}

void			reset(int *a, int *b)
{
	*a = 0;
	*b = 0;
	g_f.z = 0;
	g_f.s = 0;
	g_f.p = 0;
}
