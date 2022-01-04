/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_reading2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:32:27 by yaziz             #+#    #+#             */
/*   Updated: 2021/01/08 17:27:36 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/file_retriever.h"

void	write_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	params_verif(int ac, char **av)
{
	if (ac < 2)
		write_exit("Error\nPlease provide <cub> file as argument");
	else if (ac == 3)
	{
		if (ft_strlen(av[2]) == 6 && av[2][0] == '-' && av[2][1] == '-' &&
				av[2][2] == 's' && av[2][3] == 'a' &&
				av[2][4] == 'v' && av[2][5] == 'e')
			g_save = 1;
		else
			write_exit("Error\nCheck provided arguments");
	}
	else if (ac > 3)
		write_exit("Error\nCheck provided arguments");
}

void	treat_no(char *s)
{
	shouldspaceskip(&s, 2);
	if (!*s)
		write_exit("Error\nNo value assigned to NO element");
	g_file.no = ft_strdup(s);
	g_tkn.no += 1;
	if (g_tkn.no == 2)
		write_exit("Error\nMore than one NO detected in <cub> file");
}

void	treat_so(char *s)
{
	shouldspaceskip(&s, 2);
	if (!*s)
		write_exit("Error\nNo value assigned to SO element");
	g_file.so = ft_strdup(s);
	g_tkn.so += 1;
	if (g_tkn.so == 2)
		write_exit("Error\nMore than one SO detected in <cub> file");
}

void	treat_we(char *s)
{
	shouldspaceskip(&s, 2);
	if (!*s)
		write_exit("Error\nNo value assigned to WE element");
	g_file.we = ft_strdup(s);
	g_tkn.we += 1;
	if (g_tkn.we == 2)
		write_exit("Error\nMore than one WE detected in <cub> file");
}
