/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:59:51 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/29 13:39:37 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int			count(int n)
{
	int i;

	i = (n == 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char			*p;
	unsigned int	hold;
	int				i;

	i = count(n);
	i += n < 0 ? 1 : 0;
	p = (char *)malloc(i + 1);
	if (!p)
		return (NULL);
	p[i--] = 0;
	if (n == 0)
	{
		p[0] = 48;
		return (p);
	}
	p[0] = n < 0 ? '-' : 'x';
	hold = (n < 0) ? n * -1 : n;
	while (hold)
	{
		p[i--] = hold % 10 + 48;
		hold /= 10;
	}
	return (p);
}
