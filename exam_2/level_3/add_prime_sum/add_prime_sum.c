/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:07:28 by eproust           #+#    #+#             */
/*   Updated: 2024/11/06 18:09:35 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);	
}

int	ft_atoi(char *s)
{
	int	n;

	n = 0;
	while (*s)
		n = n * 10 + *s++ - '0';
	return (n);
}

int	ft_isprime(int n)
{
	int	i;

	if (n == 2)
		return (1);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	get_primes_sum(char *nb)
{
	int	n;
	int	i;
	int	sum;

	n = ft_atoi(nb);
	sum = 0;
	i = 2;
	while (i <= n)
	{
		if (ft_isprime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int ac, char **av)
{
	int	sum;

	if (ac != 2)
		write(1, "0", 1);
	else
	{
		sum = get_primes_sum(av[1]);
		ft_putnbr(sum);
	}
	write (1, "\n", 1);
}
