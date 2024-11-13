/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:57:10 by eproust           #+#    #+#             */
/*   Updated: 2024/11/11 18:58:30 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int	*range;
	int	len;
	int	i;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	i = 0;
	while (i < len)
	{
		range[i] = start;
		i++;
		if (start <= end)
			start++;
		else
			start--;
	}
	return (range);
}

/*
#include <stdio.h>

int	main(void)
{
	int	a = 0;
	int	b = -3;
	int	len;
	int	*range;
	int i = 0;

	if (a <= b)
		len = b - a + 1;
	else
		len = a - b + 1;
	range = ft_range(a, b);
	if (!range)
		return (1);
	while (i < len)
		printf("%i, ", range[i++]);
	free(range);
	return (0);
}
*/
