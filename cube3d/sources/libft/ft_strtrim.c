/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 20:56:24 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/28 15:32:38 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		carac_counter(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		func_hel(int *i, int *j, char *s1, char *set)
{
	int holf;

	*i = 0;
	holf = carac_counter(s1) - 1;
	*j = 0;
	while (s1[*i])
	{
		while (s1[*i] != set[*j] && set[*j])
			(*j)++;
		if (s1[*i] != set[*j])
		{
			holf = *i;
			break ;
		}
		(*i)++;
		(*j) = 0;
	}
	(*j) = 0;
	(*i) = carac_counter(s1) - 1;
	return (holf);
}

static char		*func_hel_zwei(int *j, int *holf, int *hols, char *s1)
{
	char *p;

	p = (char *)malloc(*hols - *holf + 2);
	if (p == NULL)
		return (NULL);
	if (*hols == *holf)
	{
		p[0] = 0;
		return (p);
	}
	*j = 0;
	while (*holf <= *hols)
	{
		p[*j] = s1[*holf];
		(*holf)++;
		(*j)++;
	}
	p[*j] = 0;
	return (p);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		holf;
	int		hols;
	char	*p;

	if (s1 == NULL || set == NULL)
		return (char *)(s1 == NULL ? NULL : s1);
	holf = func_hel(&i, &j, (char *)s1, (char *)set);
	hols = carac_counter((char *)s1) - 1;
	while (i > holf)
	{
		while (s1[i] != set[j] && set[j])
			j++;
		if (s1[i] != set[j])
		{
			hols = i;
			break ;
		}
		i--;
		j = 0;
	}
	p = func_hel_zwei(&j, &holf, &hols, (char *)s1);
	return ((p == NULL) ? NULL : p);
}
