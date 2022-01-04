/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:34:00 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 15:53:26 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	treat_c(char *s)
{
	int r;
	int g;
	int b;

	treatcolors(&r, &g, &b, &s);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		write_exit("Error\nColors are invalid");
	r <<= 16;
	g <<= 8;
	g_file.ceil = r + g + b;
	g_tkn.c += 1;
	if (g_tkn.c == 2)
		write_exit("Error\nMore than one C detected in <cub> file");
}

int		skipwhitesp(char **s)
{
	while (**s == ' ')
		(*s)++;
	return (0);
}

int		fileargend(char *s, int f)
{
	while (*s == ' ')
		s++;
	if (!*s)
		return (1);
	if (f)
		write_exit("Error\nResolution Error");
	else
		write_exit("Error\nColors Error");
	return (0);
}

void	shouldspace(char *s, int f)
{
	if (*s != ' ' && f == 1)
		write_exit("Error\nResolution Error");
	if (*s != ' ' && f == 0)
		write_exit("Error\nColors Error");
	if (*s != ' ' && f == 2)
		write_exit("Error\nPaths Error");
}

void	shouldspaceskip(char **s, int f)
{
	shouldspace(*s, f);
	skipwhitesp(s);
}
