/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:07:19 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 13:41:03 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *nb)
{
	int	n;

	n = 0;
	while (*nb)
	{
		n = n * 10 + *nb - '0';
		nb++;
	}
	return (n);
}

void	ft_putnbr(unsigned int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	tab_mult(char *nb)
{
	int	n;
	int	i;

	n = ft_atoi(nb);
	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(av[1]);
	else
	(1, "\n", 1);
}
