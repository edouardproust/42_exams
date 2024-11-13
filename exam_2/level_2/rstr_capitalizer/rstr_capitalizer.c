/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:25:06 by eproust           #+#    #+#             */
/*   Updated: 2024/11/12 17:54:22 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_isspace(char c)
{
	return (c == '\0' || c == ' ' || c == '\t' || c == '\v');
}

void	rstr_cap(char *s)
{
	char	c;
	int		i;

	i = 0;
	while (s[i])
	{
		c = s[i];
		if ('a' <= c && c <= 'z' && (ft_isspace(s[i + 1])))
			c -= 32;
		else if ('A' <= c && c <= 'Z' && !(ft_isspace(s[i + 1])))
			c += 32;
		write(1, &c, 1);
		s++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (av[i])
			rstr_cap(av[i++]);
	}
	return (0);
}
