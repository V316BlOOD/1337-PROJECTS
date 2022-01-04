/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:07:02 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:15:43 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	texturize(int i, int txt, int dis, int k)
{
	float	step;
	int		j;
	int		color;

	j = 0;
	if (g_ray[i].hh)
		g_ray[i].offh = (int)g_ray[i].hit.x % 64;
	else
		g_ray[i].offh = (int)g_ray[i].hit.y % 64;
	step = 64.0 / (float)(dis + k);
	while (j < dis)
	{
		g_ray[i].offv = (j + k / 2) * step;
		color = get_txt_color(txt, g_ray[i].offh, g_ray[i].offv);
		addpxl(i, j + (g_file.win_y / 2) - (dis / 2), color);
		j++;
	}
}

void	drawslice(void)
{
	int		i;
	float	dis;
	float	cdis;
	int		k;
	float	constt;

	constt = (g_file.win_x / 2 / tan(M_PI / 3 / 2));
	i = 0;
	k = 0;
	while (i < g_file.win_x)
	{
		dirreset(i);
		cdis = g_ray[i].dis * cos(g_ray[i].dir - g_player.dir);
		dis = (g_config.singsq / cdis) * constt;
		if (dis > g_file.win_y)
		{
			k = dis - g_file.win_y;
			dis = g_file.win_y;
		}
		texturize(i, g_ray[i].wallface, dis, k);
		k = 0;
		i++;
	}
}

int		redcross(int key, void *useless)
{
	(void)useless;
	(void)key;
	mlx_destroy_window(g_windat.mlx, g_windat.winp);
	exit(0);
}

int		is_wall(int x, int y)
{
	if (x < 0 || x >= g_file.map_w * 64 || y >= g_file.map_h * 64 || y < 0)
		return (1);
	if (g_file.map[y / g_config.singsq][x / g_config.singsq] == '1'
	|| g_file.map[y / g_config.singsq][x / g_config.singsq] == ' ')
		return (1);
	return (0);
}

int		is_spr(int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (g_file.map[y / g_config.singsq][x / g_config.singsq] == '2')
		return (1);
	return (0);
}
