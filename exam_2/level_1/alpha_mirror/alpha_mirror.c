/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:05:15 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 21:31:45 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

int		alpha_mirror_char(char c)
{
	char	*alphabet;
	int		i;
	
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	i = 0;
	while (alphabet[i] && alphabet[i] != c)
		i++;
	return (alphabet[25 - i]);
}

void	alpha_mirror(char *s)
{
	char	c;
	int		maj;

	while (*s)
	{
		c = *s;
		maj = 0;
		if (('a' <= *s && *s <= 'z') || ('A' <= *s && *s <= 'Z' ))
		{
			if ('A' <= *s && *s <= 'Z')
			{
				maj = 1;
				c += 32;
			}
			c = alpha_mirror_char(c);
			if (maj)
				c -= 32;
		}
		write(1, &c, 1);
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
	return (0);
}
