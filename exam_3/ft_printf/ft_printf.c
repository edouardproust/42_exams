/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:08:24 by eproust           #+#    #+#             */
/*   Updated: 2025/01/14 20:29:42 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i]);
	return (i);
}

int	ft_putstr(const char *str)
{
	size_t	written;

	written = 0;
	if (str == NULL)
		written = write(1, "(null)", 6);
	else
	{
		while (*str)
		written += write(1, str++, 1);
	}
	return (written);
}

int	ft_puthexa(unsigned int n, int written)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		written = ft_puthexa(n / 16, written);		
	written += write(1, &base[n % 16], 1);
	return (written);
}

int	ft_putnbr(int n, int written)
{
	long	nl;
	char	c;

	nl = (long)n;
	if (nl < 0)
	{
		nl = -nl;
		written += write(1, "-", 1);
	}
	if (nl >= 10)
		written = ft_putnbr(nl / 10, written);
	c = nl % 10 + '0';
	written += write(1, &c, 1);
	return (written);
}

int	ft_printf(const char *fmt, ...)
{
	int		written;
	va_list	ap;
	int		flag;
	char	*s;
	int		d;
	int		x;

	written = 0;
	va_start(ap, fmt);
	flag = 0;
	while (*fmt)
	{
		if (flag == 0 && *fmt == '%')
			flag = 1;
		else if (flag == 0)
			written += write(1, fmt, 1);
		else if (flag == 1)
		{
			flag = 0;
			if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				written += ft_putstr(s);
			}
			else if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				written += ft_putnbr(d, 0);
			}
			else if (*fmt == 'x')
			{
				x = va_arg(ap, int);
				written += ft_puthexa(x, 0);
			}
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
	int	written = 0;
	char *s = NULL;
	int	d = INT_MIN;
	int x = UINT_MAX;

	written = ft_printf("string: '%s', int: '%d', hexa: '%x'\n", s, d, x);
	printf("written (ft_printf): %d\n", written);
	written = printf("string: '%s', int: '%d', hexa: '%x'\n", s, d, x);
	printf("written (printf): %d\n", written);
	written = ft_printf("%s\n", "toto");
	written = ft_printf("Magic %s is %d\n", "number", 42);
	written = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	return (0);
}
*/
