/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:02:05 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 17:15:46 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int	n;
	int	neg;

	while (ft_isspace(*str))
		str++;
	neg = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	n = 0;
	while ('0' <= *str && *str <= '9')
		n = n * 10 + *str++ - '0';
	return (n * neg);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Use: ./atoi \"<arg1:int>\"\n");
		return (1);
	}
	printf("ft_atoi(\"%s\") = %d\n", av[1], ft_atoi(av[1]));
	printf("atoi(\"%s\") = %d\n", av[1], atoi(av[1]));
	return (0);
}
*/
