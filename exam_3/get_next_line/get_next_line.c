/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:55:38 by eproust           #+#    #+#             */
/*   Updated: 2025/01/21 11:27:21 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

void	ft_free(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int	i;

	sub = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	static char	*stash = NULL;
	char	*line = NULL;
	char	*buffer;
	int		bytes_read;
	char	*new_stash;
	int		i;
	int		line_len;
	int		stash_len;
	char	*stash_tmp;

	// fill_stash
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(stash, buffer);
		ft_free(&stash);
		stash = new_stash;
	}
	ft_free(&buffer);
	
	// fill_line
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0' && i > 0)
		i--;
	line = ft_substr(stash, 0, i + 1);
	
	// exit_condition
	line_len = ft_strlen(line);
	if (line_len == 0)
	{
		ft_free(&line);
		ft_free(&stash);
		return (NULL);
	}

	// update_stash
	stash_len = ft_strlen(stash);
	if (stash_len == line_len)
		ft_free(&stash);
	else
	{
		stash_tmp = ft_substr(stash, i + 1, ft_strlen(stash));
		ft_free(&stash);
		stash = stash_tmp;
	}

	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test", O_RDONLY);
	
	while (1)
	{
		char *line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
}
*/
