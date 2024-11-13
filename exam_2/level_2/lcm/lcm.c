/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:34:03 by eproust           #+#    #+#             */
/*   Updated: 2024/11/13 22:16:44 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		lcm = a;
	else
		lcm = b;
	while(1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
	return (lcm);
}

/*
int	main(void)
{
	unsigned int	a = 41;
	unsigned int	b = 3;

	printf("lcm(%d, %d) = %d", a, b, lcm(a, b));
	return (0);
}
*/
