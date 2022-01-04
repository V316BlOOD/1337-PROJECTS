/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:36:47 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 15:51:57 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	assignplayerdir(char c)
{
	if (c == 'N')
		g_player.dir = 3 * M_PI_2;
	else if (c == 'S')
		g_player.dir = M_PI_2;
	else if (c == 'E')
		g_player.dir = 0;
	else if (c == 'W')
		g_player.dir = M_PI;
}

void	assignplayerpos(int x, int y)
{
	g_player.x = x * g_config.singsq + g_config.singsq / 2;
	g_player.y = y * g_config.singsq + g_config.singsq / 2;
}

void	playerassign(int *nop, int i, int j, char **map)
{
	(*nop)++;
	assignplayerdir(map[i][j]);
	assignplayerpos(j, i);
}

void	verify_player(char **map, int w, int h)
{
	int i;
	int j;
	int nop;

	i = -1;
	j = -1;
	nop = 0;
	while (++i < h)
	{
		while (++j < w)
		{
			if (is_map_element(map[i][j]) || map[i][j] == ' ')
			{
				if (is_p(map[i][j]))
					playerassign(&nop, i, j, map);
			}
			else
				write_exit("Error\nBad character in map");
		}
		j = -1;
	}
	if (nop == 0)
		write_exit("Error\nNo player detected in map");
	else if (nop > 1)
		write_exit("Error\nMore than one player detected in map");
}

void	addsprite(t_sprite to_add)
{
	t_sprite *temp;

	temp = malloc(sizeof(t_sprite) * (g_sprcount ? g_sprcount : 1));
	temp[g_sprcount ? g_sprcount - 1 : 0] = to_add;
	if (g_spr)
		ft_memcpy(temp, g_spr, sizeof(t_sprite) * (g_sprcount - 1));
	if (g_spr)
		free(g_spr);
	g_spr = temp;
}
