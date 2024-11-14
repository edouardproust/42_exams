/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:22:24 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 02:31:39 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	do_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
		return (a / b);
	else if (op == '%')
		return (a % b);
	return (0);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;
	
	if (ac == 4)
	{
		a = atoi(av[1]);
		b = atoi(av[3]);
		printf("%d", do_op(a, b, av[2][0]));
	}
	printf("\n");
	return (0);
}
