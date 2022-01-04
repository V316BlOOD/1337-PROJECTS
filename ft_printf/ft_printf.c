/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:50:47 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/22 18:28:47 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags g_f;

int		print_int(char *s, va_list *st)
{
	int len;
	int value;
	int spaces;
	int zeroes;

	reset(&zeroes, &spaces);
	len = 0;
	zero_detect(s + 1, st);
	spaces_detect(s + 1, st);
	point_detect(s + 1, st);
	value = va_arg(*st, int);
	zeroes = reducer(s, &spaces, value, 0);
	if (spaces >= 0)
		len += print_s(spaces - GR(zeroes, ncount(value)) - NEG(value) + CO);
	len += print_z(zeroes - ncount(value), (value >= 0 ? 0 : 1));
	if (value == -2147483648)
		ft_putunbr(2147483648);
	else if (!is_point(s + 1) || g_f.p != 0 || value != 0)
		ft_putnbr_fd(ABS(value), 1);
	else
		len -= 1;
	if (spaces < 0)
		len += print_s(-spaces - GR(zeroes, ncount(value)) - NEG(value) + CO);
	return (len + ncount(value) + (value < 0 ? 1 : 0));
}

int		print_pointer(char *s, va_list *st)
{
	int				len;
	unsigned long	value;
	int				spaces;
	int				zeroes;
	int				size;

	reset(&zeroes, &spaces);
	zero_detect(s + 1, st);
	spaces_detect(s + 1, st);
	point_detect(s + 1, st);
	value = va_arg(*st, unsigned long);
	tohex8(value, &size, 0);
	len = 2;
	zeroes = reducer(s, &spaces, 1, 1);
	if (spaces >= 0)
		len += print_s(spaces - GR(zeroes, size + 2) + CO);
	write(1, "0x", 2);
	len += print_z(zeroes - size, 0);
	if (!is_point(s + 1) || g_f.p != 0 || value != 0)
		tohex8(value, &size, 1);
	else
		len -= 1;
	if (spaces < 0)
		len += print_s(ABS(spaces) - GR(zeroes, size + 2) + CO);
	return (len + size);
}

int		print_hex(char *s, va_list *st, char font)
{
	int				len;
	unsigned int	value;
	int				spaces;
	int				zeroes;
	int				size;

	reset(&zeroes, &spaces);
	zero_detect(s + 1, st);
	spaces_detect(s + 1, st);
	point_detect(s + 1, st);
	value = va_arg(*st, unsigned int);
	tohex(value, 0, &size, 0);
	len = 0;
	zeroes = reducer(s, &spaces, 1, 0);
	if (spaces >= 0)
		len += print_s(spaces - GR(zeroes, size) + CO);
	len += print_z(zeroes - size, 0);
	if (!is_point(s + 1) || g_f.p != 0 || value != 0)
		tohex(value, font, &size, 1);
	else
		len -= 1;
	if (spaces < 0)
		len += print_s(ABS(spaces) - GR(zeroes, size) + CO);
	return (len + size);
}

int		print_uint(char *s, va_list *st)
{
	int				len;
	unsigned int	value;
	int				spaces;
	int				zeroes;

	reset(&zeroes, &spaces);
	len = 0;
	zero_detect(s + 1, st);
	spaces_detect(s + 1, st);
	point_detect(s + 1, st);
	value = va_arg(*st, unsigned int);
	zeroes = reducer(s, &spaces, 1, 0);
	if (spaces >= 0)
		len += print_s(spaces - GR(zeroes, uncount(value)) + CO);
	len += print_z(zeroes - uncount(value), 0);
	if (!is_point(s + 1) || g_f.p != 0 || value != 0)
		ft_putunbr(value);
	else
		len -= 1;
	if (spaces < 0)
		len += print_s(ABS(spaces) - GR(zeroes, uncount(value)) + CO);
	return (len + uncount(value));
}

int		ft_printf(const char *s, ...)
{
	int		k;
	int		printed;
	va_list	st;

	va_start(st, s);
	printed = 0;
	k = 0;
	while (s[k])
	{
		if (s[k] != '%')
		{
			write(1, s + k, 1);
			++printed;
			k++;
		}
		else if (s[k] == '%')
		{
			printed += print_format(&st, format_finder(s + k), (char *)s + k);
			k += skip((char *)s + k + 1) + 1;
		}
	}
	va_end(st);
	return (printed);
}
