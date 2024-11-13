/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:52:17 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 13:04:55 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char	binary[9];
	int		i;

	i = 0;
	while (i < 8)
		binary[i++] = '0';
	i--;
	binary[8] = '\0';
	while (octet > 0)
	{
		binary[i--] = octet % 2 + '0';
		octet /= 2;
	}
	i = 0;
	while (binary[i])
		write(1, &binary[i++], 1);
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		print_bits(*av[1] - '0');
	printf("\n");
	return (0);
}
*/
