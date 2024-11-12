/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:03:45 by eproust           #+#    #+#             */
/*   Updated: 2024/11/12 20:38:34 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v');
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*get_start(char *s)
{
	while (*s && ft_isspace(*s))
		s++;
	return (s);
}

char	*get_first_word(char *s)
{
	char	*first;

	while (*s && ft_isspace(*s))
		s++;
	first = s;
	while (*s && !ft_isspace(*s))
		s++;
	while (*s && ft_isspace(*s))
		s++;
	if (*s != '\0')
		first = s;
	return (first);
}

char	*copy_trim(char *s)
{
	char	*cpy;
	char	*st;
	char	*fi;
	int		i;
	int		j;

	cpy = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	st = get_start(s);
	fi = get_first_word(s);
	i = 0;
	if (st == fi)
	{
		while (fi[i] && !ft_isspace(fi[i]))
		{
			cpy[i] = fi[i];
			i++;
		}
		return (cpy);
	}
	j = 0;
	while (fi[i])
	{
		if (!ft_isspace(fi[i]) || (ft_isspace(fi[i]) && i > 0 && !ft_isspace(fi[i - 1])))
			cpy[j++] = fi[i];
		i++;
	}
	if (cpy[j - 1] != ' ')
	{
		cpy[j] = ' ';
		j++;
	}
	while (!ft_isspace(*st))
		cpy[j++] = *st++;
	return (cpy);
}

char	*rostring(char *s)
{
	char	*out;

	out = copy_trim(s);
	if (!out)
		return (NULL);
	return (out);
}

int	main(int ac, char **av)
{
	char	*out;
	int		i;

	if (ac > 1)
	{
		out = rostring(av[1]);
		if (!out)
			return (1);
		i = 0;
		while (out[i])
			write(1, &out[i++], 1);
		free(out);	
	}
	write(1, "\n", 1);
}
