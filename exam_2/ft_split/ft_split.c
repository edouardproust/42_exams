/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:41:57 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 15:05:57 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

char	*word_dup(char *s)
{
	char	*word;
	int		len;
	int		i;
	
	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && !ft_isspace(s[len]))
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	count_words(char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!in_word && !ft_isspace(*s))
		{
			count++;
			in_word = 1;
		}
		else if (in_word && ft_isspace(*s))
			in_word = 0;
		s++;
	}
	return (count);
}

/*
void	free_split(char **split, int fail_index)
{
	int	i;

	i = 0;
	while (i < fail_index)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
}
*/

char	**ft_split(char *s)
{
	char	**split;
	int		words;
	int		i;
	int		in_word;

	words = count_words(s);
	split = malloc (sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	in_word = 0;
	i = 0;
	while (*s)
	{
		if (!in_word && !ft_isspace(*s))
		{
			split[i] = word_dup(s);
			if (!split[i])
				return (NULL);	
			//	return (free_split(split, i), NULL);
			i++;	
			while (*s && !ft_isspace(*s))
				s++;
		}
		else if (ft_isspace(*s))
		{
			s++;
			if (in_word)
				in_word = 0;
		}
	}
	split[i] = NULL;
	return (split);
}

/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**split;
	int		i;

	if (ac != 2)
		return (1);

	split = ft_split(av[1]);
	if (!split)
		return(1);
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}
*/
