/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaziz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:14:51 by yaziz             #+#    #+#             */
/*   Updated: 2019/10/25 00:50:14 by yaziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int					is_whitesp(char c)
{
	int conda;
	int condb;

	conda = (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f');
	condb = (c == '\r');
	return (conda || condb ? 1 : 0);
}

int							ft_atoi(const char *str)
{
	int					i;
	unsigned long long	stepper;
	int					neutrum;
	int					cond;

	i = 0;
	neutrum = 0;
	stepper = 0;
	while (str[i] != '-' && str[i] != '+' && is_whitesp(str[i]))
		i++;
	neutrum = ((str[i] == '-') ? -1 : 1);
	(str[i] == '-' || str[i] == '+') ? ++i : 0;
	cond = (str[i] > '9' || str[i] < '0');
	if (!is_whitesp(str[i]) && (str[i] > '9' || str[i] < '0'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		stepper = (stepper * 10) + (str[i] - 48);
		i++;
	}
	if (stepper > 2147483648)
		return (-1);
	return (int)(stepper * neutrum);
}
