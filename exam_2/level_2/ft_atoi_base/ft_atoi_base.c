/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:49:21 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 23:28:24 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_index(char c, int str_base)
{	
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (base[i] && i < str_base && base[i] != c)
		i++;
	if (i == 16)
		return (-1);
	return (i);
}

int	is_alphanum(char c)
{
	return (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		n;
	char	c;
	int		neg;
	int		i;

	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	n = 0;
	while (*str)
	{
		c = *str;
		if (!is_alphanum(c))
			break;
		if ('A' <= c && c <= 'Z')
			c += 32;
		i = base_index(c, str_base);
		if (i >= 0)
			n = n * str_base + i;
		str++;
	}
	return (n * neg);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";
	int		str_base = 16;

	printf("%d\n", ft_atoi_base(str, str_base));
	return (0);
}
*/
