/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:08:32 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/29 13:38:10 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (s == NULL)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		p[0] = 0;
	else
	{
		i = 0;
		while ((size_t)i < len && s[i])
		{
			p[i] = s[i + start];
			++i;
		}
		p[i] = '\0';
	}
	return (p);
}
