/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:15:14 by eproust           #+#    #+#             */
/*   Updated: 2025/01/20 20:21:51 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

static void	free_ptr(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

static int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*str_chr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

static char	*str_sub(char *s, int start, int len)
{
	char	*sub;
	int		i;

	sub = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[start] && i < len)
		sub[i++] = s[start++]; 
	sub[i] = '\0';
	return (sub);
}

static char	*str_join(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (s1 == NULL)
		return (str_sub(s2, 0, str_len(s2)));
	join = malloc(sizeof(char) * (str_len(s1) + str_len(s2) + 1));
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	int			br;
	char		*new_stash;
	int			i;
	int			line_len;
	int			stash_len;
	char		*stash_tmp;

	// fill_stash
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[0] = '\0';
	br = 1;
	while (!str_chr(buffer, '\n') && br > 0)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		buffer[br] = '\0';
		new_stash = str_join(stash, buffer);
		free_ptr(&stash);
		stash = new_stash;
	}
	free(buffer);

	// set_line
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0' && i > 0)
		i--;
	line = str_sub(stash, 0, i + 1);

	// gnl end condition
	if (str_len(line) == 0)
	{
		free_ptr(&line);
		free_ptr(&stash);
		return (NULL);
	}

	// update_stash
	line_len = str_len(line);
	stash_len = str_len(stash);
	if (stash_len == line_len)
		free_ptr(&stash);
	else
	{
		stash_tmp = str_sub(stash, line_len, stash_len);
		free_ptr(&stash);
		stash = stash_tmp;
	}
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*file = "./test";
	int		fd;
	char	*s;

	fd = open(file, O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break;
		printf("%s", s);
		free(s);
	}
	return (0);
}
*/
