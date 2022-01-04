/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:09:37 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:19:11 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	next_2dframe(void)
{
	makeamove();
	clrimage();
	castrays();
	drawslice();
	rendersprites();
	if (!g_save)
		mlx_put_image_to_window(g_windat.mlx, g_windat.winp, g_frame.img, 0, 0);
}

void	move_forward(void)
{
	float nextx;
	float nexty;
	float tx;
	float ty;

	if (g_mot.up)
	{
		nextx = g_player.x + cos(g_player.dir) * MV_SPEED;
		nexty = g_player.y + sin(g_player.dir) * MV_SPEED;
		tx = g_player.x + cos(g_player.dir) * (MV_SPEED + 20);
		ty = g_player.y + sin(g_player.dir) * (MV_SPEED + 20);
		if (!is_wall(nextx, nexty) && !is_wall(tx, ty) && !is_spr(nextx, nexty))
		{
			g_player.x = nextx;
			g_player.y = nexty;
		}
	}
}

void	move_backward(void)
{
	float nextx;
	float nexty;
	float tx;
	float ty;

	if (g_mot.down)
	{
		nextx = g_player.x + cos(g_player.dir) * MV_SPEED * -1;
		nexty = g_player.y + sin(g_player.dir) * MV_SPEED * -1;
		tx = g_player.x + cos(g_player.dir) * (MV_SPEED + 20) * -1;
		ty = g_player.y + sin(g_player.dir) * (MV_SPEED + 20) * -1;
		if (!is_wall(nextx, nexty) && !is_wall(tx, ty) && !is_spr(nextx, nexty))
		{
			g_player.x = nextx;
			g_player.y = nexty;
		}
	}
}

void	move_leftward2(void)
{
	float nextx;
	float nexty;
	float tx;
	float ty;

	if (g_mot.leftm)
	{
		nextx = g_player.x + cos(g_player.dir - M_PI_2) * MV_SPEED;
		nexty = g_player.y + sin(g_player.dir - M_PI_2) * MV_SPEED;
		tx = g_player.x + cos(g_player.dir - M_PI_2) * (MV_SPEED + 20);
		ty = g_player.y + sin(g_player.dir - M_PI_2) * (MV_SPEED + 20);
		if (!is_wall(nextx, nexty) && !is_wall(tx, ty) && !is_spr(nextx, nexty))
		{
			g_player.x = nextx;
			g_player.y = nexty;
		}
	}
}

void	move_rightward2(void)
{
	float nextx;
	float nexty;
	float tx;
	float ty;

	if (g_mot.rightm)
	{
		nextx = g_player.x + cos(g_player.dir + M_PI_2) * MV_SPEED;
		nexty = g_player.y + sin(g_player.dir + M_PI_2) * MV_SPEED;
		tx = g_player.x + cos(g_player.dir + M_PI_2) * (MV_SPEED + 20);
		ty = g_player.y + sin(g_player.dir + M_PI_2) * (MV_SPEED + 20);
		if (!is_wall(nextx, nexty) && !is_wall(tx, ty) && !is_spr(nextx, nexty))
		{
			g_player.x = nextx;
			g_player.y = nexty;
		}
	}
}
