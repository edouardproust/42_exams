/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:47:06 by eproust           #+#    #+#             */
/*   Updated: 2024/11/06 20:53:44 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	get_words_len(char *snake_str)
{
	int		chars;

	chars = 0;
	while (*snake_str)
	{	
		if (*snake_str != '_')
			chars++;
		snake_str++;
	}
	return (chars);
}

char	*snake_to_camel(char *s)
{
	char	*camel_str;
	int		len;
	int		i;
	int		j;

	len = get_words_len(s);
	camel_str = malloc(sizeof(char) * (len + 1));
	if (!camel_str)
		return (0);
	camel_str[len] = '\0';
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '_')
		{
			if (i > 0 && s[i - 1] == '_')
					camel_str[j] = s[i] - 32;
			else
				camel_str[j] = s[i];
			j++;
		}
		i++;
	}
	return (camel_str);
}

int	main(int ac, char **av)
{
	char	*s;
	int		i;

	if (ac == 2)
	{
		s = snake_to_camel(av[1]);
		if (!s)
			return (1);
		i = 0;
		while (s[i])
			write(1, &s[i++], 1);
		free(s);
	}
	write(1, "\n", 1);
	return (0);
}
