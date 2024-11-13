/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:28:54 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 14:36:27 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	int				largest;
	unsigned int	i;

	largest = 0;
	i = 0;
	while (i < len)
	{
		if (tab[i] > largest)
			largest = tab[i];
		i++;
	}
	return (largest);
}

/*
#include <stdio.h>

int	main(void)
{
	int	largest;

	int	nbs[10] = {2, 42, 1, 6, 9, 3, 2, 1, 0, 5};
	largest = max(nbs, sizeof(nbs) / sizeof(nbs[0]));
	printf("%d", largest);
	return (0);
}
*/
