/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:36:48 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/19 15:57:01 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern t_flags g_f;

void		tohex(unsigned int number, char font, int *size, char aff)
{
	char	s[9];
	int		i;

	i = 0;
	while (number >= 16)
	{
		if ((number % 16) < 10)
			s[i] = (number % 16) + '0';
		else
			s[i] = (number % 16) - 10 + (font == 1 ? 'A' : 'a');
		number /= 16;
		i++;
	}
	if (number < 10)
		s[i] = number + '0';
	else
		s[i] = number - 10 + (font == 1 ? 'A' : 'a');
	*size = (int)i + 1;
	if (aff)
		while (i >= 0)
			my_putchar(s[i--]);
}

void		tohex8(unsigned long number, int *size, char aff)
{
	char	s[20];
	int		i;

	i = 0;
	while (number >= 16)
	{
		if ((number % 16) < 10)
			s[i] = (number % 16) + '0';
		else
			s[i] = (number % 16) - 10 + 'a';
		number /= 16;
		i++;
	}
	if (number < 10)
		s[i] = number + '0';
	else
		s[i] = number - 10 + 'a';
	*size = (int)i + 1;
	if (aff)
		while (i >= 0)
			my_putchar(s[i--]);
}

int			ft_putstr(char *s, int size)
{
	int i;

	i = 0;
	while (size && s[i])
	{
		my_putchar(s[i]);
		i++;
		size--;
	}
	return (i);
}

int			uncount(unsigned int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			ncount(int n)
{
	int i;

	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	i = 0;
	n = (n < 0 ? -n : n);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
