/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:05:30 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/15 16:39:23 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	freethemap(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_file.map_h)
		free(g_file.map[i++]);
	free(g_file.map);
}

void	freethatgame(void)
{
	free(g_ray);
	free(g_spr);
	freethemap();
}

void	setbmp(void)
{
	int picfile;

	g_bmp.fsize = 54 + 3 * g_file.win_x * g_file.win_y;
	g_bmp.bpp = 24;
	g_bmp.file = malloc(54 + 3 * g_file.win_x * g_file.win_y);
	*((short *)g_bmp.file) = 0b0100110101000010;
	*((int *)(g_bmp.file + 2)) = g_bmp.fsize;
	*((int *)(g_bmp.file + 6)) = 0;
	*((int *)(g_bmp.file + 10)) = 54;
	*((int *)(g_bmp.file + 14)) = 40;
	*((int *)(g_bmp.file + 18)) = g_file.win_x;
	*((int *)(g_bmp.file + 22)) = g_file.win_y;
	*((short *)(g_bmp.file + 26)) = 1;
	*((short *)(g_bmp.file + 28)) = 24;
	*((int **)(g_bmp.file + 30)) = 0;
	*((int **)(g_bmp.file + 38)) = 0;
	*((int *)(g_bmp.file + 46)) = 0;
	*((int *)(g_bmp.file + 50)) = 0;
	picfile = open("frame.bmp", O_WRONLY | O_CREAT
			| O_TRUNC, S_IRUSR | S_IWUSR);
	write(picfile, g_bmp.file, 54);
	next_2dframe();
	write(picfile, g_bmp.file + 54, 3 * g_file.win_x * g_file.win_y);
	free(g_bmp.file);
	freethatgame();
}

int		existing_sprite(int xmap, int ymap)
{
	int i;

	i = 0;
	while (i < g_sprcount)
	{
		if (g_spr[i].x / 64 == xmap && g_spr[i].y / 64 == ymap)
			return (1);
		i++;
	}
	return (0);
}

void	initenv(void)
{
	int		i;
	float	firstraydir;

	g_ray = malloc(g_file.win_x * sizeof(t_ray));
	g_config.defsize = M_PI / 3;
	g_config.rayspace = g_config.defsize / g_file.win_x;
	firstraydir = g_player.dir - (g_file.win_x / 2) * g_config.rayspace;
	i = 0;
	while (i < g_file.win_x)
	{
		g_ray[i++].dir = firstraydir;
		firstraydir += g_config.rayspace;
	}
	if (!g_save)
	{
		g_frame.img = mlx_new_image(g_windat.mlx, g_file.win_x, g_file.win_y);
		g_frame.addr = mlx_get_data_addr(g_frame.img, &g_frame.bits_per_pixel,
				&g_frame.line_length, &g_frame.endian);
		g_windat.winp = mlx_new_window(g_windat.mlx,
				g_file.win_x, g_file.win_y, "Raycaster Engine - CUBE 3D");
	}
	g_mot = (t_motion){.up = 0, .down = 0, .leftm = 0,
		.leftt = 0, .rightm = 0, .rightt = 0};
	load_textures();
	castrays();
}
