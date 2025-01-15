/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:27:24 by eproust           #+#    #+#             */
/*   Updated: 2025/01/15 14:58:04 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	put_string(char *s)
{
	int	written;

	written = 0;
	if (s == NULL)
		written = write(1, "(null)", 6);
	else
	{
		while (*s)
			written += write(1, s++, 1);
	}
	return (written);
}

static int	put_decimal(int n, int written)
{
	char	c;
	long	nl;

	nl = (long)n;
	if (nl < 0)
	{
		written += write(1, "-", 1);
		nl = -nl;
	}
	if (nl >= 10)
		written = put_decimal(nl / 10, written);
	c = nl % 10 + '0';
	written += write(1, &c, 1);
	return (written);
}

static int	put_hexa(unsigned int n, int written)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		written = put_hexa(n / 16, written);
	written += write(1, &base[n % 16], 1);
	return (written);
}

static int	put_format(va_list ap, char c)
{
	int				written;
	char			*s;
	int				d;
	unsigned int	x;

	written = 0;
	if (c == 's')
	{
		s = va_arg(ap, char *);
		written = put_string(s);
	}
	else if (c == 'd')
	{
		d = va_arg(ap, int);
		written = put_decimal(d, 0);
	}
	else if (c == 'x')
	{
		x = va_arg(ap, unsigned int);
		written = put_hexa(x, 0);
	}
	return (written);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		written;
	int		flag;

	va_start(ap, fmt);
	written = 0;
	flag = 0;
	while (*fmt)
	{
		if (flag == 0 && *fmt == '%')
			flag = 1;
		else if (flag == 0)
			written += write(1, fmt, 1);
		else if (flag == 1)
		{
			written += put_format(ap, *fmt);
			flag = 0;
		}
		fmt++;
	}
	return (written);
}

/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char *s1 = NULL;
	char *s2 = "Hello world!";
	int	d = INT_MIN;
	int	x = UINT_MAX;
	int	res = 0;

	res = ft_printf("s1: '%s', s2: '%s', int: '%d', hexa: '%x'\n", s1, s2, d, x);
	printf("written (ft_printf): %d\n", res);
	res = printf("s1: '%s', s2: '%s', int: '%d', hexa: '%x'\n", s1, s2, d, x);
	printf("written (printf): %d\n", res);
	return (0);
}
*/
