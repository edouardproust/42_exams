/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:55:37 by eproust           #+#    #+#             */
/*   Updated: 2024/11/12 17:15:50 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	left;
	unsigned char	right;

	left = octet >> 4;
	right = octet & 0b00001111;
	right <<= 4;
	return (right | left);
}

/*
#include <unistd.h>

void	print_bits(unsigned char n)
{
	char	c;

	if (n > 1)
		print_bits(n / 2);
	c = n % 2 + '0';
	write(1, &c, 1);
}


int	main(int ac, char **av)
{
	unsigned char	octet;

	if (ac != 2)
	{
		printf("Use: ./swap_bits \"<arg1:char>\"");
		return (1);
	}
	octet = av[1][0];

	write(1, "input: '", 8);
	print_bits(octet);
	write(1, "'\nswap: '", 9);

	octet = swap_bits(octet);
	print_bits(octet);
	write(1, "'\n", 2);
}
*/
