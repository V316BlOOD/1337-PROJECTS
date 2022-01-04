/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rendering2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 16:06:27 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 17:34:08 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	addpxl(int x, int y, int color)
{
	char	*dst;

	if (x >= g_file.win_x || y >= g_file.win_y || x < 0 || y < 0)
		return ;
	if (!g_save)
	{
		dst = g_frame.addr + (y * g_frame.line_length
				+ x * (g_frame.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
	else
	{
		dst = (g_bmp.file + 54) +
			(g_file.win_y - 1 - y) * g_file.win_x * 3 + x * 3;
		dst[0] = *((char *)&color + 0);
		dst[1] = *((char *)&color + 1);
		dst[2] = *((char *)&color + 2);
	}
}

void	drawvertical(int x, int y, int distance, int color)
{
	int i;

	i = 0;
	while (i < distance)
	{
		addpxl(x, i + y, color);
		i++;
	}
}

void	clrimage(void)
{
	int i;
	int j;
	int half;

	i = 0;
	j = 0;
	half = g_file.win_y / 2;
	while (i < half)
	{
		while (j < g_file.win_x)
			addpxl(j++, i, g_file.ceil);
		i++;
		j = 0;
	}
	while (i < g_file.win_y)
	{
		while (j < g_file.win_x)
			addpxl(j++, i, g_file.floor);
		i++;
		j = 0;
	}
}

void	load_textures(void)
{
	int		uslss;
	int		i;
	char	*txts[5];

	i = 0;
	txts[1] = trimpath(g_file.no);
	txts[2] = trimpath(g_file.ea);
	txts[3] = trimpath(g_file.so);
	txts[4] = trimpath(g_file.we);
	txts[0] = trimpath(g_file.s);
	while (i < 5)
	{
		g_txt[i].fr.img = mlx_xpm_file_to_image(g_windat.mlx,
				txts[i], &uslss, &uslss);
		if (!g_txt[i].fr.img)
			write_exit("Error\nCheck provided XPM files");
		g_txt[i].fr.addr = mlx_get_data_addr(g_txt[i].fr.img,
				&g_txt[i].fr.bits_per_pixel, &g_txt[i].fr.line_length,
				&g_txt[i].fr.endian);
		i++;
	}
}

int		get_txt_color(int txt, int x, int y)
{
	if (x >= 0 && x < 64 && y >= 0 && y < 64)
		return (*((int *)g_txt[txt].fr.addr + y * 64 + x));
	return (0);
}
