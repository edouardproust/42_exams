/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:38:56 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 14:52:34 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	common_denominator(int a, int b)
{
	int	min;

	min = a;
	if (b < a)
		min = b;
	while (min > 1)
	{
		if (a % min == 0 && b % min == 0)
			return (min);
		min--;
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	res;

	if (ac == 3)
	{
		res = common_denominator(atoi(av[1]), atoi(av[2]));
		ft_putnbr(res);
	}
	write(1, "\n", 1);	
	return (0);
}
