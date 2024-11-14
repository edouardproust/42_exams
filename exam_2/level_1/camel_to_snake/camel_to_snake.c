/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:18:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 01:46:18 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	isup(char c)
{
	return ('A' <= c && c <= 'Z');
}

int	snake_len(char *camel)
{
	int	len;

	len = 0;
	while (*camel)
	{
		if (isup(*camel))
			len++;
		len++;
		camel++;
	}
	return (len);
}

char	*camel_to_snake(char *camel)
{
	int		len;
	char	*snake;
	int		i;
	int		j;

	len = snake_len(camel);
	snake = malloc(sizeof(char) * (len + 1));
	if (!snake)
		return (NULL);
	i = 0;
	j = 0;
	while (camel[i])
	{
		if (isup(camel[i]))
		{
			snake[j++] = '_';
			camel[i] += 32;
		}
		else
			snake[j++] = camel[i++];
	}
	snake[j] = '\0';
	return (snake);	
}

int	main(int ac, char **av)
{
	char	*res;
	int		i;

	if (ac == 2)
	{
		res = camel_to_snake(av[1]);
		i = 0;
		while (res[i])
			write(1, &res[i++], 1);
		free(res);
	}
	write(1, "\n", 1);
	return (0);
}
