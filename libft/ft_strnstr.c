/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:03:50 by yaziz             #+#    #+#             */
/*   Updated: 2019/11/02 16:40:29 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cp;
	char	*i;
	char	*k;

	if (!(needle[0]))
		return (char *)(haystack);
	while (*haystack && len)
	{
		if (*haystack == needle[0])
		{
			cp = len;
			i = (char*)haystack;
			k = (char*)needle;
			while (*i == *k && cp-- && *k && *i)
			{
				++i;
				++k;
			}
			if (!*k)
				return ((char *)haystack);
		}
		++haystack;
		--len;
	}
	return (NULL);
}
