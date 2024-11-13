/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:19:27 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 17:37:32 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int	len;
	int	i;

	len = end - start + 1;
	if (start > end)
		len = start - end + 1;
	range = malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (end > start)
			range[i++] = end--;
		else
			range[i++] = end++;
	}
	return (range);
}

/*
#include <stdio.h>

int	main(void)
{
	int	a = 1;
	int	b = 2;

	int	len;
	len = b - a + 1;
	if (a > b)
		len = a - b + 1;
	int	*range = ft_rrange(a, b);
	if (!range)
		return (1);
	printf("%d", range[0]);
	int	i = 1;
	while (i < len)
		printf(", %d", range[i++]);
	free(range);
	printf("\n");
}
*/
