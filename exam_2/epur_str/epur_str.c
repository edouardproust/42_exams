/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:55:26 by eproust           #+#    #+#             */
/*   Updated: 2024/11/09 17:20:32 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	epur_str(char *s)
{
	int		in_word;

	in_word = 0;
	while (*s)
	{
		if (*s != ' ' || (*s == ' ' && in_word && *(s + 1)))
			write(1, s, 1);
		if (*s == ' ' && in_word)
			in_word = 0;	
		if (*s != ' ' && !in_word)
			in_word = 1;
		s++;
	}
}

int	main(int ac, char **av)
{

	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
