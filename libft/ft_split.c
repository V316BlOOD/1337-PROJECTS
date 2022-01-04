/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:33:37 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/29 13:42:45 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		words(const char *s, char c)
{
	int i;
	int j;

	if (s[0] == 0)
		return (0);
	i = 1;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			j++;
		i++;
	}
	return (j + ((s[0] == c) ? 0 : 1));
}

static int		*vtable(const char *s, char c)
{
	int *p;
	int i;
	int verif;
	int word_len;

	i = 0;
	word_len = 0;
	verif = 0;
	p = (int *)malloc((words(s, c) * 2) * sizeof(int));
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			p[verif++] = i;
			while (s[i] != c && s[i++])
				word_len++;
			i -= !s[i - 1] ? 1 : 0;
			p[verif++] = word_len;
			word_len = 0;
		}
		i += !s[i] ? 0 : 1;
	}
	return (p);
}

static void		split_free(int j, char **p)
{
	while (j)
	{
		free(p[j]);
		j--;
	}
	free(p[j]);
	free(p);
}

static char		**split_allocation(const char *s, char c, int *vt)
{
	int		i;
	char	**p;
	int		wordss;
	int		j;

	j = 0;
	wordss = words(s, c);
	i = 1;
	p = (char **)malloc((wordss + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	while (j < wordss)
	{
		p[j] = (char *)malloc(vt[i] + 1);
		if (p[j] == NULL)
		{
			split_free(j, p);
			return (NULL);
		}
		p[j][vt[i]] = '\0';
		j++;
		i += 2;
	}
	p[wordss] = NULL;
	return (p);
}

char			**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		k;
	int		*vt;

	if (s == NULL)
		return (NULL);
	if ((vt = vtable(s, c)) == NULL)
		return (NULL);
	i = 0;
	j = -1;
	k = 0;
	if ((p = split_allocation(s, c, vt)) == NULL)
		return (NULL);
	while (p[i] != NULL)
	{
		while (++j < vt[k + 1])
			p[i][j] = s[vt[k] + j];
		k += 2;
		i++;
		j = -1;
	}
	return (p);
}
