/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:55:33 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/29 13:38:37 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		func_norminette_hacker(char *p, char *s2, int *i, int *j)
{
	while (s2[*j])
	{
		p[*i] = s2[*j];
		(*j)++;
		(*i)++;
	}
	p[*i] = 0;
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	p = (char *)malloc(i + j + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	func_norminette_hacker(p, (char *)s2, &i, &j);
	return (p);
}
