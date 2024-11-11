/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:59:13 by eproust           #+#    #+#             */
/*   Updated: 2024/11/11 15:50:01 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 1)
		return (1);
	while (n > 2)
	{
		if (n % 2 != 0)
			return (0);
		n /= 2;
	}	
	if (n == 2)
		return (1);
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", is_power_of_2(1));
	return (0);
}
*/
