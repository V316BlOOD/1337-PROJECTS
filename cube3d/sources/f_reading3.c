/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:33:04 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 15:51:07 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	treat_ea(char *s)
{
	shouldspaceskip(&s, 2);
	if (!*s)
		write_exit("Error\nNo value assigned to EA element");
	g_file.ea = ft_strdup(s);
	g_tkn.ea += 1;
	if (g_tkn.ea == 2)
		write_exit("Error\nMore than one EA detected in <cub> file");
}

void	treat_s(char *s)
{
	shouldspaceskip(&s, 2);
	if (!*s)
		write_exit("Error\nNo value assigned to S element");
	g_file.s = ft_strdup(s);
	g_tkn.s += 1;
	if (g_tkn.s == 2)
		write_exit("Error\nMore than one S detected in <cub> file");
}

void	shouldcomma(char **s)
{
	if (**s != ',')
		write_exit("Error\nColors Error");
	(*s)++;
}

void	treatcolors(int *r, int *g, int *b, char **s)
{
	shouldspaceskip(s, 0);
	shouldnumber(*s, 0);
	*r = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	skipwhitesp(s);
	shouldcomma(s);
	skipwhitesp(s);
	shouldnumber(*s, 0);
	*g = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	skipwhitesp(s);
	shouldcomma(s);
	skipwhitesp(s);
	shouldnumber(*s, 0);
	*b = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	fileargend(*s, 0);
}

void	treat_f(char *s)
{
	int r;
	int g;
	int b;

	treatcolors(&r, &g, &b, &s);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		write_exit("Error\nColors are invalid");
	r <<= 16;
	g <<= 8;
	g_file.floor = r + g + b;
	g_tkn.f += 1;
	if (g_tkn.f == 2)
		write_exit("Error\nMore than one F detected in <cub> file");
}
