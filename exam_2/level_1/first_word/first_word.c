/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:53:40 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 16:58:29 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v');
}

void	print_first_word(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	while (*s && !ft_isspace(*s))
		write(1, s++, 1);	
}

int	main(int ac, char **av)
{
	if (ac == 2)	
		print_first_word(av[1]);
	write (1, "\n", 1);
	return (0);
}
