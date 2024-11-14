/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:49:35 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 02:11:18 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	issp(char c)
{
	return (c == ' ' || c == '\t' || c == '\v');
}

void	print_expand_str(char *s)
{
	int	flag;

	flag = 0;
	while (*s)
	{
		if (!issp(*s) && issp(*(s - 1)) && flag)
			write(1, "   ", 3);
		if (!issp(*s))
		{
			flag = 1;
			write(1, s, 1);
		}
		s++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_expand_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
