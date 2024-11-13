/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:34:20 by eproust           #+#    #+#             */
/*   Updated: 2024/11/09 18:53:10 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_double(char *s1, char	*char_ptr)
{
	while (s1 < char_ptr)
	{
		if (*s1 == *char_ptr)
			return (0);
		s1++;
	}
	return (1);
}

void	inter_strs(char *s1, char *s2)
{
	char	*s1_save;
	char	*s2_save;

	s1_save = s1;
	s2_save = s2;
	while (*s1)
	{
		s2 = s2_save;
		while (*s2)
		{
			if (*s1 == *s2 && check_double(s1_save, s1))
			{
				write(1, s1, 1);
				break;
			}
			s2++;
		}
		s1++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		inter_strs(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
