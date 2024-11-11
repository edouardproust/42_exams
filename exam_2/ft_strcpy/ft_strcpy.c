/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:44:22 by eproust           #+#    #+#             */
/*   Updated: 2024/11/11 14:56:22 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	dst1[20];
	char	dst2[20];

	if (ac != 2)
	{
		printf("Use: ./strcpy \"String to copy here\"");
		return (1);
	}
	printf("ft_strcpy: '%s'\n", ft_strcpy(dst1, av[1]));
	printf("strcpy: '%s'\n", strcpy(dst2, av[1]));
}
*/
