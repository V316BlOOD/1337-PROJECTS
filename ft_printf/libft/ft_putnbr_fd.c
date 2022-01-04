/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 23:12:35 by yaziz             #+#    #+#             */
/*   Updated: 2019/12/22 15:35:31 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	my_putchar(char c, int fd)
{
	write(1, &c, fd);
}

int			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(1, "-", fd);
		ft_putnbr_fd(214748364, fd);
		write(1, "8", fd);
		return (n);
	}
	if (n < 0)
	{
		my_putchar('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		my_putchar(n % 10 + '0', fd);
	}
	if (n < 10)
	{
		my_putchar(n % 10 + '0', fd);
	}
	return (n);
}
