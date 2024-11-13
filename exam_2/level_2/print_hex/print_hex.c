/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:29:22 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 20:44:19 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *s)
{
	int n;

	n = 0;
	while (*s)
	{
		if ('0' <= *s && *s <= '9')
			n = n * 10 + *s - '0';
		s++;
	}
	return (n);
}

void	print_hex(int n)
{
	char	*base = "0123456789abcdef";

	if (n > 15)
		print_hex(n / 16);
	write(1, &base[n % 16], 1);
}

int	main(int ac, char **av)
{
	int	n;

	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		print_hex(n);
	}
	write(1, "\n", 1);
	return (0);
}
