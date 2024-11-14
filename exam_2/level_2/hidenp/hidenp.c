/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:03:59 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 14:33:12 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static char	*ft_strchr(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (s);
		s++;
	}
	return (NULL);
}

int	hidenp(char *s1, char *s2)
{
	char	*i;

	if (*s1 == '\0')
		return (1);
	while (*s1)
	{
		i = ft_strchr(*s1, s2);
		if (!i)
			return (0);
		s2 += (i - s2) + 1;
		s1++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	res;

	if (ac == 3)
	{
		res = hidenp(av[1], av[2]) + '0';
		write(1, &res, 1);
	}
	write(1, "\n", 1);
	return (0);
}
