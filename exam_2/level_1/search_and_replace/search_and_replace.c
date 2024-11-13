/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:05:43 by eproust           #+#    #+#             */
/*   Updated: 2024/11/06 16:16:13 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	search_n_replace(char *s, char search, char replace)
{
	while (*s)
	{
		if (*s == search)
			*s = replace;
		s++;
	}
}

int main(int ac, char **av)
{
	if (ac == 4 && (ft_strlen(av[2]) == 1 || ft_strlen(av[3]) == 1))
	{
		search_n_replace(av[1], *av[2], *av[3]);
		write(1, av[1], ft_strlen(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
