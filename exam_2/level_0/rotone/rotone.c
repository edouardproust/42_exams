/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:27:40 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 11:51:09 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotate_alpha(char c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
	{
		if (c == 'z' || c == 'Z')
			c -= 25;
		else
			c += 1;
	}
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1])
			rotate_alpha(*av[1]++);
	}
	write(1, "\n", 1);
}
