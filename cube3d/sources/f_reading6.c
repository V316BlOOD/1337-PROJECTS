/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:35:33 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:47:00 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	treat_m(char *element)
{
	char **temp;

	if (g_file.map == NULL)
	{
		g_file.mapread = 1;
		check_before_map();
		g_file.map = malloc(sizeof(char *));
		if (!g_file.map)
			exit(-1);
		g_file.map[0] = ft_strdup(element);
		g_file.map_h = 1;
		g_file.map_w = ft_strlen(element);
		g_tkn.map = 1;
		g_file.lwidth = 0;
		g_file.lwidth = countline(g_file.lwidth, element);
	}
	else
		mapnewline(&temp, &element);
}

int		skip_spaces(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ')
		i++;
	return (i);
}

void	treat_element(char *element)
{
	int i;

	i = skip_spaces(element);
	if (element[i] == 'N' && element[i + 1] == 'O')
		treat_no(element + 2 + i);
	else if (element[i] == 'S' && element[i + 1] == 'O')
		treat_so(element + 2 + i);
	else if (element[i] == 'W' && element[i + 1] == 'E')
		treat_we(element + 2 + i);
	else if (element[i] == 'E' && element[i + 1] == 'A')
		treat_ea(element + 2 + i);
	else if (element[i] == 'R')
		treat_r(element + 1 + i);
	else if (element[i] == 'S')
		treat_s(element + 1 + i);
	else if (element[i] == 'F')
		treat_f(element + 1 + i);
	else if (element[i] == 'C')
		treat_c(element + 1 + i);
	else if (is_map_element(element[i]) && !g_file.mapend)
		treat_m(element);
	else if (!element[i])
		return ;
	else
		write_exit("Error\n<cub> file isn't well defined");
}

void	treat_line(char *line)
{
	treat_element(line);
}

int		empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 0 && i > 0)
		write_exit("Error\nEmpty line with spaces detected");
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	if (g_file.mapread)
		g_file.mapend = 1;
	return (1);
}
