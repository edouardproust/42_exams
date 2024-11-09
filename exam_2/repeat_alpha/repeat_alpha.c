/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:27:53 by eproust           #+#    #+#             */
/*   Updated: 2024/11/09 18:29:49 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char c)
{
	char	ch;
	char	*alphabet;
	int		i;
	int		j;

	ch = c;
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	if ('A' <= c && c <= 'Z')
		c += 32;
	if (('a' <= c && c <= 'z'))	
	{
		i = 0;
		while (c != alphabet[i])
			i++;
		j = 0;
		while (j <= i)
		{
			write(1, &ch, 1);
			j++;
		}
	}
	else
		write(1, &ch, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1])
			repeat_alpha(*av[1]++);
	}
	write (1, "\n", 1);
	return (0);
}
