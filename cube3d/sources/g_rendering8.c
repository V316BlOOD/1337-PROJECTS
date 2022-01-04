/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:10:00 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 17:30:10 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	move_leftward(void)
{
	if (g_mot.leftt)
		g_player.dir -= TRN_SPEED;
}

void	move_rightward(void)
{
	if (g_mot.rightt)
		g_player.dir += TRN_SPEED;
}

void	makeamove(void)
{
	move_forward();
	move_backward();
	move_leftward();
	move_rightward();
	move_leftward2();
	move_rightward2();
}

int		handleentry(int key, void *useless)
{
	(void)useless;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(g_windat.mlx, g_windat.winp);
		freethatgame();
		exit(0);
	}
	if (key == KEY_UP || key == KEY_W)
		g_mot.up = 1;
	if (key == KEY_DOWN || key == KEY_S)
		g_mot.down = 1;
	if (key == KEY_LEFT)
		g_mot.leftt = 1;
	if (key == KEY_RIGHT)
		g_mot.rightt = 1;
	if (key == KEY_A)
		g_mot.leftm = 1;
	if (key == KEY_D)
		g_mot.rightm = 1;
	return (0);
}

int		stopmot(int key, void *useless)
{
	(void)useless;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(g_windat.mlx, g_windat.winp);
		exit(0);
	}
	if (key == KEY_UP || key == KEY_W)
		g_mot.up = 0;
	if (key == KEY_DOWN || key == KEY_S)
		g_mot.down = 0;
	if (key == KEY_LEFT)
		g_mot.leftt = 0;
	if (key == KEY_RIGHT)
		g_mot.rightt = 0;
	if (key == KEY_A)
		g_mot.leftm = 0;
	if (key == KEY_D)
		g_mot.rightm = 0;
	return (0);
}
