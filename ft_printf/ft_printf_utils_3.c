/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:23:50 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/24 22:02:07 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_flags g_f;

void	point_detect(char *s, va_list *st)
{
	int i;

	i = 0;
	while (!IS_FORMAT(s[i]) && s[i] != '.')
		i++;
	if (s[i] == '.')
	{
		if (s[i + 1] != '*')
			g_f.p = ft_atoi(s + i + 1);
		else
			g_f.p = va_arg(*st, int);
	}
}

void	zero_detect(char *s, va_list *st)
{
	int i;

	i = 0;
	if (s[0] == '0')
	{
		if (s[1] != '*')
			g_f.z = ft_atoi(s + 1);
		else
			g_f.z = va_arg(*st, int);
	}
}

void	spaces_detect(char *s, va_list *st)
{
	int i;
	int	j;

	i = 0;
	if (s[0] == '*')
		g_f.s = va_arg(*st, int);
	else if (s[0] == '-')
	{
		while (s[i] == '-')
			i++;
		if (s[i] == '*' && s[i - 1] == '-')
		{
			j = va_arg(*st, int);
			g_f.s = ABS(j) * -1;
		}
		else if (s[i] == '*' && s[i - 1] != '-')
			g_f.s = va_arg(*st, int);
		else
			g_f.s = ft_atoi(s + i - 1);
	}
	else
		g_f.s = ft_atoi(s);
}

int		print_char(char *s, va_list *st)
{
	int		len;
	char	value;
	int		spaces;
	int		zeroes;

	reset(&zeroes, &spaces);
	len = 0;
	zero_detect(s + 1, st);
	spaces_detect(s + 1, st);
	value = va_arg(*st, int);
	spaces = g_f.s;
	if (spaces >= 0)
		len += print_s(spaces - zeroes - 1);
	len += print_z(zeroes - 1, 0);
	my_putchar(value);
	if (spaces < 0)
		len += print_s(ABS(spaces) - zeroes - 1);
	return (len + 1);
}

int		print_string(char *s, va_list *st)
{
	int		len;
	char	*value;
	int		spaces;
	int		precision;

	reset(&precision, &spaces);
	len = 0;
	spaces_detect(s + 1, st);
	point_detect(s + 1, st);
	value = va_arg(*st, char *);
	if (!value)
		value = "(null)";
	precision = ft_strlen(value);
	spaces = g_f.s;
	if (is_point(s + 1) && (g_f.p < 0 || g_f.p >= (int)ft_strlen(value)))
		precision = ft_strlen(value);
	else if (is_point(s + 1) && g_f.p >= 0)
		precision = g_f.p;
	if (spaces >= 0)
		len += print_s(spaces - precision);
	len += ft_putstr(value, precision);
	if (spaces < 0)
		len += print_s(ABS(spaces) - precision);
	return (len);
}
