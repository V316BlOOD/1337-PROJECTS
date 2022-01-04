/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:38:46 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/19 15:48:57 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s(int n)
{
	int temp;

	temp = n;
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
	return (temp <= 0 ? 0 : temp);
}

int		print_z(int n, int is_neg)
{
	int temp;

	temp = n;
	if (is_neg)
		write(1, "-", 1);
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
	return (temp <= 0 ? 0 : temp);
}

int		is_point(char *s)
{
	int i;

	i = 0;
	while (!IS_FORMAT(s[i]) && s[i] != '.')
		i++;
	return (s[i] == '.' ? 1 : 0);
}

char	format_finder(const char *s)
{
	int i;

	i = 1;
	while (!IS_FORMAT(s[i]) && (IS_FLAG(s[i]) || ft_isdigit(s[i])))
		i++;
	return (s[i]);
}

int		skip(char *s)
{
	int i;

	i = 0;
	while (IS_FLAG(s[i]) || ft_isdigit(s[i]))
		i++;
	return (i + 1);
}
