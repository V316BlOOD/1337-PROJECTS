/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:07:33 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:16:14 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	dirreset(int i)
{
	while (g_ray[i].dir < 0)
		g_ray[i].dir += 2 * M_PI;
	while (g_ray[i].dir > 2 * M_PI)
		g_ray[i].dir -= 2 * M_PI;
}

float	normangle(float angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	checkhit(int i)
{
	if (g_ray[i].hh == 1)
		g_ray[i].wallface = (g_ray[i].up == -1 ? 3 : 1);
	else if (g_ray[i].hh == 0)
		g_ray[i].wallface = (g_ray[i].right == -1 ? 4 : 2);
}

void	equaldistances(float dis2, t_pt b, int i)
{
	g_ray[i].dis = dis2;
	g_ray[i].hit = b;
	g_ray[i].wallface = i ? g_ray[i - 1].wallface : 1;
	g_ray[i].hh = g_ray[i].wallface == 1 || g_ray[i].wallface == 3 ? 2 : 0;
}

void	rayassigndis(int i, t_pt a, t_pt b)
{
	float dis1;
	float dis2;

	dis1 = MAX_INT;
	dis2 = MAX_INT;
	if (a.x != -1)
		dis1 = (int)hypotf(a.x - g_player.x, a.y - g_player.y);
	if (b.x != -1)
		dis2 = (int)hypotf(b.x - g_player.x, b.y - g_player.y);
	if (dis1 < dis2)
	{
		g_ray[i].dis = dis1;
		g_ray[i].hit = a;
		g_ray[i].hh = 1;
	}
	else if (dis1 > dis2)
	{
		g_ray[i].dis = dis2;
		g_ray[i].hit = b;
		g_ray[i].hh = 0;
	}
	else
		equaldistances(dis2, b, i);
	checkhit(i);
}
