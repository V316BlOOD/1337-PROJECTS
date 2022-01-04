/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:10:50 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/25 22:15:47 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_flags g_f;

int		print_percentage(char *s, va_list *st)
{
	int spaces;
	int zeroes;
	int len;
	int k;

	reset(&spaces, &zeroes);
	len = 1;
	if ((k = skip_zm(&s)))
		k = -1;
	zero_detect(s, st);
	spaces_detect(s, st);
	point_detect(s, st);
	if (s[0] == '0' && g_f.z < 0)
		spaces = (k == -1 ? ABS(g_f.z) * k : g_f.z);
	else if (s[0] != '0')
		spaces = (k == -1 ? ABS(g_f.s) * k : g_f.s);
	if (s[0] == '0' && g_f.z >= 0)
		zeroes = g_f.z;
	if (spaces >= 0)
		len += print_s(spaces - GR(zeroes, 1));
	len += print_z(zeroes - 1, 0);
	my_putchar('%');
	if (spaces < 0)
		len += print_s(ABS(spaces) - GR(zeroes, 1));
	return (len);
}

int		skip_zm(char **s)
{
	int i;
	int z;
	int m;

	z = 0;
	m = 0;
	i = 1;
	while (*(*s + i) == '0' || *(*s + i) == '-')
	{
		if (*(*s + i) == '0')
			z = 1;
		else if (*(*s + i) == '-')
			m = 1;
		i++;
	}
	if (z && m)
		*s += i;
	else
		*s += 1;
	return (z && m ? 1 : 0);
}
