/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:37:37 by eproust           #+#    #+#             */
/*   Updated: 2025/01/21 13:30:15 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	put_str(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (*s)
		count += write(1, s++, 1);
	return (count); 
}

int	put_decimal(int n, int count)
{
	long	nl;
	char	c;

	nl = (long)n;
	if (nl < 0)
	{
		count += write(1, "-", 1);
		nl = -nl;
	}
	if (nl >= 10)
		count = put_decimal(nl / 10, count);
	c = nl % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	put_hexa(unsigned int n, int count)
{
	char	*base = "0123456789abcdef";

	if (n >= 16)
		count = put_hexa(n / 16, count);
	count += write(1, &base[n % 16], 1);
	return (count);
}

int ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		flag;
	char	*s;
	int		d;
	unsigned int	x;

	va_start(ap, fmt);
	count = 0;
	flag = 0;
	while (*fmt)
	{
		if (flag == 0 && *fmt == '%')
			flag = 1;
		else if (flag == 0)
			count += write(1, fmt, 1);
		else if (flag == 1)
		{
			flag = 0;
			if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				count += put_str(s);
			}
			else if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				count += put_decimal(d, 0);
			}
			else if (*fmt == 'x')
			{
				x = va_arg(ap, unsigned int);
				count += put_hexa(x, 0);
			}
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}

/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *s1 = "Hello world";
	char *s2 = NULL;
	int d = INT_MIN;
	unsigned int x = UINT_MAX;
	int	count;

	count = ft_printf("s1: '%s', s2: '%s', d: '%d', x: '%x'\n", s1, s2, d, x);
	printf("count ft_printf: %d\n", count);
	count = printf("s1: '%s', s2: '%s', d: '%d', x: '%x'\n", s1, s2, d, x);
	printf("count printf: %d\n", count);
	return (0);
}
*/
