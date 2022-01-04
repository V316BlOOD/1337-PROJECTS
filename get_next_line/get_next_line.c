/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:14:24 by yaziz             #+#    #+#             */
/*   Updated: 2019/11/15 00:12:09 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_second(char **saved_var, char **line, char **str)
{
	ssize_t temp;

	if (*saved_var && (temp = f(*saved_var, '\n')) != -1)
	{
		if (!(*line = cut(*saved_var, temp)) ||
				!(*saved_var = duplicate(*saved_var + temp + 1, saved_var)))
			return (-1);
		return (free_ret(str, 1));
	}
	return (0);
}

int		get_next_line_third(char **saved_var, char **str, char **line)
{
	if (*saved_var && **saved_var)
	{
		if (!(*line = cut(*saved_var, f(*saved_var, 0))))
			return (-1);
		free_ret(saved_var, 0);
		return (free_ret(str, 0));
	}
	if (!(*line = duplicate("", NULL)))
		return (-1);
	free_ret(str, 0);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*saved_var;
	char			*str;
	ssize_t			temp;
	ssize_t			readed;

	if (BUFFER_SIZE <= 0 || !line || read(fd, NULL, 0) == -1 ||
		!(str = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((readed = read(fd, str, BUFFER_SIZE)))
	{
		str[readed] = 0;
		saved_var = save(saved_var, str);
		if ((temp = f(saved_var, '\n')) != -1)
		{
			if (!(*line = cut(saved_var, temp)) ||
			!(saved_var = duplicate(saved_var + temp + 1, &saved_var)))
				return (-1);
			return (free_ret(&str, 1));
		}
	}
	if ((temp = get_next_line_second(&saved_var, line, &str)))
		return (temp);
	return (get_next_line_third(&saved_var, &str, line));
}
