/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:41:22 by yaziz             #+#    #+#             */
/*   Updated: 2019/11/14 20:02:18 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t		f(char *s, char c)
{
	ssize_t i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (s[i] == c ? i : -1);
}

char		*cut(char *str, ssize_t index)
{
	char	*s;
	ssize_t i;

	i = 0;
	if (!(s = (char *)malloc(index + 1)))
		return (NULL);
	while (i < index)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

char		*save(char *saving_var, char *second_str)
{
	char *temporary1;
	char *temporary2;
	char *new_saving_var;

	if (!saving_var)
	{
		saving_var = (char *)malloc(1);
		saving_var[0] = 0;
	}
	temporary1 = saving_var;
	if (!(new_saving_var = malloc(f(temporary1, 0) + f(second_str, 0) + 1)))
		return (NULL);
	temporary2 = new_saving_var;
	while (*saving_var)
		*new_saving_var++ = *saving_var++;
	while (*second_str)
		*new_saving_var++ = *second_str++;
	*new_saving_var = 0;
	free_ret(&temporary1, 0);
	return (temporary2);
}

int			free_ret(char **p, int ret)
{
	free(*p);
	*p = NULL;
	return (ret);
}

char		*duplicate(char *dup, char **tofree)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(new = (char *)malloc(f(dup, 0) + 1)))
		return (NULL);
	while (dup[i])
	{
		new[i] = dup[i];
		i++;
	}
	new[i] = 0;
	if (tofree)
		free_ret(tofree, 0);
	return (new);
}
