/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 03:01:08 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 04:16:42 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strchr(char c, char *s)
{
	while(*s)
	{
		if (c == *s)
			return (s);
		s++;
	}
	return (NULL);
}

int	hidenp(char *s1, char *s2)
{
	while (*s1)
	{
		s2 = ft_strchr(*s1, s2);
		if (!s2)
			return (0);
		s2++;
		s1++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	c;

	if (ac == 3)
	{
		c = hidenp(av[1], av[2]) + '0';
		write(1, &c, 1);
	}
	write (1, "\n", 1);
	return (0);
}
