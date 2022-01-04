/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:08:53 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:18:36 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	sortsprites(void)
{
	int			i;
	int			j;
	t_sprite	swap;

	i = 0;
	j = 0;
	while (i < g_sprcount - 1)
	{
		while (j < g_sprcount - 1)
		{
			if (g_spr[j].dis < g_spr[j + 1].dis)
			{
				swap = g_spr[j];
				g_spr[j] = g_spr[j + 1];
				g_spr[j + 1] = swap;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		distwall_sprite(int ray, int sprite)
{
	if (ray >= 0 && ray < g_file.win_x && g_ray[ray].dis > g_spr[sprite].dis)
		return (1);
	else
		return (0);
}

void	drawsingsp(int k)
{
	float	i;
	float	j;
	int		col;
	int		m;
	int		l;

	i = 0;
	m = -1;
	l = -1;
	j = 0;
	while (++l < g_spr[k].size)
	{
		while (++m < g_spr[k].size)
		{
			if (!((col = get_txt_color(0, j, i)) <= 0)
					&& distwall_sprite(m + g_spr[k].xp, k))
				addpxl(m + g_spr[k].xp, l + g_file.win_y / 2
						- g_spr[k].size / 2, col);
			j += 64.0 / g_spr[k].size;
		}
		j = 0;
		m = 0;
		i += 64.0 / g_spr[k].size;
	}
}

void	drawsprites(void)
{
	int dx;
	int dy;
	int i;

	i = 0;
	while (i < g_sprcount)
	{
		dx = g_spr[i].x - g_player.x;
		dy = g_spr[i].y - g_player.y;
		g_player.dir = g_ray[g_file.win_x / 2].dir;
		g_spr[i].angle = atan2(dy, dx);
		while (g_spr[i].angle - g_player.dir > M_PI)
			g_spr[i].angle -= 2 * M_PI;
		while (g_spr[i].angle - g_player.dir < -M_PI)
			g_spr[i].angle += 2 * M_PI;
		g_spr[i].size = (g_file.win_x / g_spr[i].dis) * 64;
		g_spr[i].xp = (g_spr[i].angle - g_player.dir) * g_file.win_x
			/ (M_PI / 3) + (g_file.win_x / 2 - g_spr[i].size / 2);
		drawsingsp(i);
		i++;
	}
}

void	rendersprites(void)
{
	spritenewdis();
	sortsprites();
	drawsprites();
}
