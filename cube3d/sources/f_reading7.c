/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:35:56 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 15:51:50 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	fill_spaces(char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = 0;
}

int		linelength(char *str)
{
	int i;

	i = ft_strlen(str) - 1;
	while (str[i] == ' ')
		i--;
	return (i);
}

void	adjust_map(void)
{
	int		i;
	char	**new;

	if (!g_tkn.map)
		write_exit("Error\nPlease check  well <cub> file");
	i = -1;
	new = malloc(g_file.map_h * sizeof(char *));
	if (!new)
		exit(-1);
	while (++i < g_file.map_h)
	{
		new[i] = malloc(g_file.lwidth + 1);
		if (!new[i])
			exit(-1);
		fill_spaces(new[i], g_file.lwidth);
	}
	i = -1;
	while (++i < g_file.map_h)
		ft_memcpy(new[i], g_file.map[i], linelength(g_file.map[i]) + 1);
	i = -1;
	while (++i < g_file.map_h)
		free(g_file.map[i]);
	free(g_file.map);
	g_file.map = new;
	g_file.map_w = g_file.lwidth;
}

void	verify_map(char **map, int w, int h)
{
	int i;
	int j;

	i = -1;
	while (++i < w)
		if ((map[0][i] != '1' && map[0][i] != ' ') ||
		(map[h - 1][i] != '1' && map[h - 1][i] != ' '))
			write_exit("Error\nMap should be rounded by 1's 00");
	i = -1;
	while (++i < h)
		if ((map[i][0] != '1' && map[i][0] != ' ') ||
				(map[i][w - 1] != '1' && map[i][w - 1] != ' '))
			write_exit("Error\nMap should be rounded by 1's 11");
	i = 0;
	j = 0;
	while (++i < h - 1)
	{
		while (++j < w - 1)
			if (is_zsp(map[i][j]) && (map[i - 1][j] == ' '
			|| map[i][j - 1] == ' ' || map[i][j + 1] == ' '
			|| map[i + 1][j] == ' '))
				write_exit("Error\nMap should be rounded by 1's");
		j = 0;
	}
}
