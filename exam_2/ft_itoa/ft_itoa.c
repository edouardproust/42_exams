/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:30:27 by eproust           #+#    #+#             */
/*   Updated: 2024/11/09 20:20:59 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_itoa_len(int nbr)
{
	int	count;

	if (nbr == 0)
		return (1);
	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr *= -1;
	}	
	while (nbr > 0)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}
char	*ft_itoa(int nbr)
{
	char	*s;
	int		len;
	int		neg;

	len = ft_itoa_len(nbr);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);	
	s[len] = '\0';
	if (nbr == 0)
	{
		s[0] = '0';
		return (s);
	}
	neg = 0;
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	while (len > 0)
	{
		s[len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	if (neg)
		s[len] = '-';
	return (s);
}

/*
#include <stdio.h>

int	ft_atoi(char *s)
{
	int	n;
	int	neg;

	n = 0;
	neg = 1;
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	while (*s)
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (n * neg);
}

int	main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = ft_itoa(ft_atoi(av[1]));
		if (str)
		{
			printf("%s", str);
			free(str);
		}
	}
	printf("\n");
	return (0);
}
*/
