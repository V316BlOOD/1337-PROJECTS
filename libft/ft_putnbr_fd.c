/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:12:35 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/25 04:27:11 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		power(int a, int b)
{
	int i;
	int res;

	i = 0;
	res = 1;
	if (b == 0)
		return (res);
	while (i < b)
	{
		res *= a;
		i++;
	}
	return (res);
}

static int		how_many(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		give_me_the_first(int *n, int *i)
{
	return ((*n / power(10, *i)) + 48);
}

static void		nor_hacker(int fd, int *n)
{
	if (*n < 0)
	{
		write(fd, "-", 1);
		*n *= -1;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	nor_hacker(fd, &n);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = how_many(n) - 1;
	while (n > 0)
	{
		c = give_me_the_first((int *)&n, &i);
		write(fd, &c, 1);
		n %= power(10, i--);
	}
}
