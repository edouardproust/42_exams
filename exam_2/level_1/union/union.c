/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:28:30 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 22:42:45 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_double(char c, char *s, int n)
{
	int	i;

	i = 0;
	while (s[i] && i < n)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_double_s2(char c, char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (is_double(c, s2, n));
}

void	print_union(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_double(s1[i], s1, i))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!is_double_s2(s2[i], s1, s2, i))
			write(1, &s2[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		print_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
