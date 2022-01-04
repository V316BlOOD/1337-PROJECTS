/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:34:44 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 15:51:22 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	shouldnumber(char *s, int f)
{
	if (!ft_isdigit(*s) && f)
		write_exit("Error\nResolution Error");
	if (!ft_isdigit(*s) && !f)
		write_exit("Error\nColors Error");
}

void	treat_r(char *s)
{
	int mx;
	int my;

	mx = 2048;
	my = 1152;
	shouldspaceskip(&s, 1);
	shouldnumber(s, 1);
	g_file.win_x = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	shouldspaceskip(&s, 1);
	shouldnumber(s, 1);
	g_file.win_y = ft_atoi(s);
	while (ft_isdigit(*s))
		s++;
	fileargend(s, 1);
	g_tkn.r += 1;
	if (g_tkn.r == 2)
		write_exit("Error\nMore  than one R detected in <cub> file");
	if (g_file.win_y > my || g_file.win_y < 0)
		g_file.win_y = my;
	if (g_file.win_x > mx || g_file.win_x < 0)
		g_file.win_x = mx;
	if (g_file.win_y == 0 || g_file.win_x == 0)
		write_exit("Error\nResolution Error");
}

int		bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int		countline(int currval, char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i--;
	i++;
	if (currval >= i)
		return (currval);
	return (i);
}

void	check_before_map(void)
{
	if (g_tkn.no == 0 || g_tkn.so == 0 || g_tkn.we == 0
			|| g_tkn.ea == 0 || g_tkn.s == 0 || g_tkn.f == 0 || g_tkn.c == 0)
		write_exit("Error\nNot all elements defined\
above the map in <cub> file");
}
