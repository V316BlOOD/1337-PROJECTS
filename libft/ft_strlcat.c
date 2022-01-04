/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 02:23:58 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/31 14:19:01 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = ft_strlen(src);
	if (!size)
		return (k);
	i = ft_strlen(dst);
	j = i;
	if (size <= i)
		return (k + size);
	while (j < size - 1 && *src)
	{
		dst[j] = *(src++);
		j++;
	}
	dst[j] = 0;
	return (k + i);
}
