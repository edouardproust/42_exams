/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:55:46 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 16:39:20 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v');
}

static int	copy_word(char *dest, char *word_ptr)
{
	int	i;

	i = 0;
	while (word_ptr[i] && !ft_isspace(word_ptr[i]))
	{
		dest[i] = word_ptr[i];
		i++;
	}
	return (i);
}

char	*rev_wstr(char *s)
{
	char	*rev;
	int		len;
	int		i;

	len = ft_strlen(s);
	rev = malloc(sizeof(char) * (len + 1));
	if (!rev)
		return (NULL);
	rev[len] = '\0';
	i = 0;
	while (len > 0)
	{
		if (ft_isspace(s[len - 1]))
			i += copy_word(&rev[i], &s[len]);
		if (ft_isspace(s[len]))
			rev[i++] = s[len];
		len--;
	}
	copy_word(&rev[i], &s[len]);
	return (rev);
}

int	main(int ac, char **av)
{
	char	*rev;

	if (ac == 2)
	{
		rev = rev_wstr(av[1]);
		if (!rev)
			return (1);
		write(1, rev, ft_strlen(rev));
		free(rev);
	}
	write(1, "\n", 1);
	return (0);
}
