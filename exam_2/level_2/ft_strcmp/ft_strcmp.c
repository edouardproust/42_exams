/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:08:34 by eproust           #+#    #+#             */
/*   Updated: 2024/11/10 20:24:42 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int    ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1 = "Hello";
	char *s2 = "HellO";

	printf("ft_strcmp: %d\n", ft_strcmp(s1, s2));
	printf("strcmp: %d\n", strcmp(s1, s2));
	return (0);
}
*/
