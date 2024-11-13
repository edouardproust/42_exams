/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:20:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/06 17:00:33 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

char	*last_word(char *s)
{
	char	*lw;
	int		in_word;

	in_word = 0;
	lw = 0;
	while (*s)
	{
		if (!in_word && !ft_isspace(*s))
		{	
			lw = s;
			in_word = 1;
		}
		else if (in_word && ft_isspace(*s))
			in_word = 0;
		s++;
	}
	return (lw);
}

int	main(int ac, char **av)
{
	char *lw;

	if (ac == 2)
	{
		lw = last_word(av[1]);
		if (lw)
		{
			while (*lw && !ft_isspace(*lw))
				write(1, lw++, 1); 	
		}
	}
	write (1, "\n", 1);
	return (0);
}
