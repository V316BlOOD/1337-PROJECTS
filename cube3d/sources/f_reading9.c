/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:37:04 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:00:56 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	checksprites(char **map, int w, int h)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g_spr = NULL;
	g_sprcount = 0;
	while (i < h)
	{
		while (j < w)
		{
			if (map[i][j] == '2')
				makesprite(j, i);
			j++;
		}
		i++;
		j = 0;
	}
}

void	retrieve_from(char *fn)
{
	int		fl;
	int		fd;
	char	*line;

	fl = ft_strlen(fn);
	if (fl < 4)
		write_exit("Error\nThe filetype isn't <cub>");
	if (fn[fl - 1] != 'b' || fn[fl - 2] != 'u'
			|| fn[fl - 3] != 'c' || fn[fl - 4] != '.')
		write_exit("Error\nThe filetype isn't <cub>");
	if ((fd = open(fn, O_RDONLY)) == -1)
		write_exit("Error\nFile doesn't exist");
	g_file.map = 0;
	fl = 1;
	while (fl)
	{
		fl = gnl(&line, fd);
		if (!empty_line(line))
			treat_line(line);
		free(line);
	}
	adjust_map();
	verify_map(g_file.map, g_file.map_w, g_file.map_h);
	verify_player(g_file.map, g_file.map_w, g_file.map_h);
	checksprites(g_file.map, g_file.map_w, g_file.map_h);
}

void	mapnewline(char ***temp, char **element)
{
	*temp = g_file.map;
	g_file.map = malloc((g_file.map_h + 1) * sizeof(char *));
	if (!g_file.map)
		exit(-1);
	ft_memcpy(g_file.map, *temp, sizeof(char *) * g_file.map_h);
	free(*temp);
	g_file.map[g_file.map_h] = ft_strdup(*element);
	g_file.map_h++;
	g_file.map_w = bigger(ft_strlen(*element), g_file.map_w);
	g_file.lwidth = countline(g_file.lwidth, *element);
}

void	read_file(int ac, char **av)
{
	g_save = 0;
	g_config.singsq = 64;
	params_verif(ac, av);
	g_file.mapend = 0;
	g_file.mapread = 0;
	retrieve_from(av[1]);
}

void	makesprite(int xmap, int ymap)
{
	float x;
	float y;
	float dis;

	x = xmap * 64 + 32;
	y = ymap * 64 + 32;
	dis = 0;
	g_sprcount++;
	addsprite((t_sprite){.x = x, .y = y, .dis = dis, .xm = xmap, .ym = ymap});
}
