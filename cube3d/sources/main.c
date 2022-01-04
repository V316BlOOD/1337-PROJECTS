/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:10:45 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 16:20:13 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

int		main(int ac, char **av)
{
	g_windat.mlx = mlx_init();
	read_file(ac, av);
	initenv();
	if (!g_save)
	{
		mlx_hook(g_windat.winp, 2, 0L, handleentry, NULL);
		mlx_hook(g_windat.winp, 3, 0L, stopmot, NULL);
		mlx_hook(g_windat.winp, 17, 1L, redcross, NULL);
		mlx_loop_hook(g_windat.mlx, (int (*)())next_2dframe, NULL);
		mlx_loop(g_windat.mlx);
	}
	else
		setbmp();
	return (0);
}
