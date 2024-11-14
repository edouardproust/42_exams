/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:07:40 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 00:10:47 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
#include <stdio.h>

int	main(void)
{
	int a = 10;
	int b = 123;

	printf("Before: a = %i, b = %i\n", a, b);
	ft_swap(&a, &b);
	printf("After: a = %i, b = %i\n", a, b);
}
*/
