/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:37:02 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 01:09:10 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	issp(char c)
{
	return (c == ' ' || c == '\t' || c == '\v');
}

static int	isuc(char c)
{
	return ('A' <= c && c <= 'Z');
}

static int	islc(char c)
{
	return ('a' <= c && c <= 'z');
}

void	print_capitalize_str(char *s)
{
	int		in_word;
	char	c;

	in_word = 0;
	while (*s)
	{
		c = *s;
		if (!in_word && !issp(c))
		{
			if (islc(c))
				c -= 32;
			in_word = 1;
		}
		else if (in_word && !issp(c))
		{
			if (isuc(c))
				c += 32;
		}
		else if (in_word && issp(c))
		{
			in_word = 0;
		}
		write(1, &c, 1);
		s++;
	}
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
		{
			print_capitalize_str(av[i++]);
			write(1, "\n", 1);
		}	
	}
	return (0);
}
