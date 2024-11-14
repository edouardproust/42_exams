/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:22:28 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 21:16:56 by eproust          ###   ########.fr       */
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

int	issp(char c)
{
	return (c == '\0' || c == ' ' || c == '\t' || c == '\v');
}

char	*first_word(char *s)
{
	while (*s && issp(*s))
		s++;
	return (s);
}

char	*second_word(char *s)
{
	s = first_word(s);
	while (*s && !issp(*s))
		s++;
	return (first_word(s));
}

void	print_word(char *s)
{
	while (*s && !issp(*s))
		write(1, s++, 1);
}

void	rostring(char *s)
{
	char	*out;
	int		len;
	char	*fir_word;
	char	*sec_word;

	len = ft_strlen(s);
	out = malloc(sizeof(char) * (len + 1));
	if (!out)
		return ;
	fir_word = first_word(s);
	sec_word = second_word(s);
	if (*sec_word == '\0')
		print_word(fir_word);
	else
	{	
		while (*sec_word)
		{
			if (!issp(*sec_word))
				write(1, sec_word, 1);
			if (!issp(*sec_word) && issp(*(sec_word + 1)))
				write(1, " ", 1);
			sec_word++;
		}
		print_word(fir_word);
	}
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}
