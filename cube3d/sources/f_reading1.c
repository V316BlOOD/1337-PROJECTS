/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:30:24 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 17:25:58 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

int		is_map_element(char x)
{
	int c;

	c = (x == 'N' || x == 'W' || x == 'S' ||
			x == 'E' || x == '2' || x == '1' || x == '0');
	return (c);
}

int		is_zsp(char x)
{
	return (x == 'N' || x == 'W' || x == 'S'
			|| x == 'E' || x == '2' || x == '0');
}

int		is_p(char x)
{
	return (x == 'N' || x == 'W' || x == 'S' || x == 'E');
}

void	tozero_tkn(void)
{
	g_tkn = (t_tkn){.map = 0, .no = 0, .so = 0, .we = 0, .ea = 0, .s = 0};
	g_tkn = (t_tkn){.f = 0, .c = 0, .r = 0};
}

int		gnl(char **line, int fd)
{
	char	c[2];
	int		i;
	char	*tm;

	i = 0;
	c[1] = 0;
	if ((*line = ft_strdup("")) == NULL)
		exit(-1);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] != '\n')
		{
			tm = *line;
			*line = ft_strjoin(*line, c);
			free(tm);
			i++;
		}
		else
			return (1);
	}
	(*line)[i] = 0;
	return (0);
}
