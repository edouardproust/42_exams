/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:52:27 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 20:06:18 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char *s)
{
	char	c;

	while (*s)
	{
		c = *s;
		if (('a' <= c && c <= 'm') || ('A' <= c && c <= 'M'))
			c += 13;			
		else if (('n' <= c && c <= 'z') || ('N' <= c && c <= 'Z'))
			c -= 13;
		write(1, &c, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rot_13(av[1]);
	write(1, "\n", 1);
	return (0);
}
