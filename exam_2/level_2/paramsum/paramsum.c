/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:36:08 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 02:46:42 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(unsigned int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);	
}

int	main(int ac, char **av)
{
	unsigned int	count;

	if (ac < 2)
		write(1, "0", 1);
	else
	{
		count = 0;
		while (*++av)
			count++;
		ft_putnbr(count);
	}
	write(1, "\n", 1);
	return (0);
}
