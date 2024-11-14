/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:13:01 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 00:34:15 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	is_rejected(char c, const char *reject)
{	
	while (*reject)
	{
		if ('A' <= c && c <= 'Z')
			c += 32;
		if ('A' <= *reject && *reject <= 'Z')
			reject += 32;	
		if (c == *reject)
			return (1);
		reject++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_rejected(s[i], reject))
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "test";
	char *reject = "es";
	 
	printf("ft_strcspn: %ld\n", ft_strcspn(s, reject));
	printf("strcspn: %ld\n", strcspn(s, reject));
	return (0);
}
*/
