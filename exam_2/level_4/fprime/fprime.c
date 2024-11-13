/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:47:06 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 21:37:37 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int n;
	
	n = 0;
	while (*s)
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (n);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	first_prime_div(int n)
{
	int	i;

	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (i);
		i++;
	}
	return (0);
}

void	fprime(unsigned int n)
{
	int	div;
	int	flag;

	flag = 0;
	div = first_prime_div(n);
	while (div)
	{
		if (flag)
			write(1, "*", 1);
		flag = 1;
		ft_putnbr(div);	
		n /= div;
		div = first_prime_div(n);
	}
	if (flag)
		write(1, "*", 1);
	ft_putnbr(n);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		if (n > 0)
			fprime(n);
	}
	write(1, "\n", 1);
	return (0);
}
