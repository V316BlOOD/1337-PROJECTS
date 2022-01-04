/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:08:14 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:17:12 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	checkvisib(int x, int y)
{
	int i;

	i = 0;
	while (i < g_sprcount)
	{
		if (g_spr[i].xm == x / 64 && g_spr[i].ym == y / 64)
			g_spr[i].v = 1;
		else
			g_spr[i].v = 0;
		i++;
	}
}

t_pt	horizontalcast(int i)
{
	t_pt	first;
	t_dists	hord;

	g_ray[i].up = g_ray[i].dir < M_PI ? -1 : 1;
	if (g_ray[i].up == 1)
		first.y = floor(g_player.y / g_config.singsq) * g_config.singsq;
	else
		first.y = floor(g_player.y / g_config.singsq)
			* g_config.singsq + g_config.singsq;
	first.x = g_player.x + (first.y - g_player.y) / tan(g_ray[i].dir);
	if (first.x < 0 || first.x >= g_config.singsq * g_file.map_w)
		return ((t_pt){.x = -1, .y = -1});
	else
	{
		hord.ydis = g_ray[i].up * g_config.singsq * -1;
		hord.xdis = hord.ydis / tan(g_ray[i].dir);
		while (!is_wall(first.x, first.y - (g_ray[i].up == 1 ? 1 : 0)))
		{
			first.x += hord.xdis;
			if (first.x < 0 || first.x >= g_config.singsq * g_file.map_w)
				return ((t_pt){.x = -1, .y = -1});
			first.y += hord.ydis;
		}
	}
	return (first);
}

t_pt	verticalcast(int i)
{
	t_pt	first;
	t_dists	verd;

	g_ray[i].right = g_ray[i].dir > M_PI_2 && g_ray[i].dir < P * 3 ? -1 : 1;
	if (g_ray[i].right == 1)
		first.x = floor(g_player.x / g_config.singsq)
			* g_config.singsq + g_config.singsq;
	else
		first.x = floor(g_player.x / g_config.singsq) * g_config.singsq;
	first.y = g_player.y + (first.x - g_player.x) * tan(g_ray[i].dir);
	if (first.y < 0 || first.y >= g_config.singsq * g_file.map_h)
		return ((t_pt){.x = -1, .y = -1});
	else
	{
		verd.xdis = g_ray[i].right * g_config.singsq;
		verd.ydis = verd.xdis * tan(g_ray[i].dir);
		while (!is_wall(first.x - (g_ray[i].right == 1 ? 0 : 1), first.y))
		{
			first.y += verd.ydis;
			if (first.y < 0 || first.y >= g_config.singsq * g_file.map_h)
				return ((t_pt){.x = -1, .y = -1});
			first.x += verd.xdis;
		}
	}
	return (first);
}

void	castrays(void)
{
	int		i;
	float	const1;
	t_pt	a;
	t_pt	b;

	i = 0;
	const1 = (g_player.dir - (g_file.win_x / 2) * g_config.rayspace);
	while (i < g_file.win_x)
	{
		g_ray[i].dir = const1 + i * g_config.rayspace;
		dirreset(i);
		a = horizontalcast(i);
		b = verticalcast(i);
		rayassigndis(i, a, b);
		i++;
	}
}

void	spritenewdis(void)
{
	int i;

	i = 0;
	while (i < g_sprcount)
	{
		g_spr[i].dis = hypotf(g_spr[i].x - g_player.x, g_spr[i].y - g_player.y);
		i++;
	}
}
