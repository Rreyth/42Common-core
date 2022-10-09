/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:21:10 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/09 05:53:03 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_check_flag(char c, char *flags)
{
	int		i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_launch_print(char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	if (c == 'i' || c == 'd')
		count = ft_putnbr_base(va_arg(arg, int), "0123456789", count);
	if (c == 'x')
		count = ft_putnbr_base(va_arg(arg, int), "0123456789abcdef", count);
	if (c == 'X')
		count = ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF", count);
	if (c == 'u')
		count = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789", count);
	if (c == 'p')
	{
		count += ft_putstr("0x");
		count = ft_putnbr_base(va_arg(arg, long), "0123456789abcdef", count);
	}
	if (c == '%')
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg;
//	char	char_tmp;
//	char	*str_tmp;
//	long	nb_tmp;

	i = 0;
	count = 0;
	va_start(arg, 0);
	while (s[i])
	{
		if (s[i] == '%' && ft_check_flag(s[i + 1], "cspdiuxX%"))
		{
			i++;
			count += ft_launch_print(s[i], arg);
/*			if (s[i] == 'c')
			{
				char_tmp = va_arg(arg, int);
				count += ft_putchar(char_tmp);
			}
			if (s[i] == 's')
			{
				str_tmp = va_arg(arg, char *);
				count += ft_putstr(str_tmp);
			}
			if (s[i] == 'i' || s[i] == 'd')
			{
				nb_tmp = va_arg(arg, int);
				count = ft_putnbr_base(nb_tmp, "0123456789", count);
			}
			if (s[i] == 'x')
			{
				nb_tmp = va_arg(arg, int);
				count = ft_putnbr_base(nb_tmp, "0123456789abcdef", count);
			}
			if (s[i] == 'X')
			{
				nb_tmp = va_arg(arg, int);
				count = ft_putnbr_base(nb_tmp, "0123456789ABCDEF", count);
			}
			if (s[i] == 'u')
			{
				nb_tmp = va_arg(arg, unsigned int);
				count = ft_putnbr_base(nb_tmp, "0123456789", count);
			}
			if (s[i] == 'p')
			{
				nb_tmp = va_arg(arg, long);
				count += ft_putstr("0x");
				count = ft_putnbr_base(nb_tmp, "0123456789abcdef", count);
			}
			if (s[i] == '%')
				count += ft_putchar(s[i]);*/
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	c = 'z';
	char	*str = "BONSOIR";
	int		n = 152;
	int		n2 = -2147483648;
	int		x = 1389;
	int		x2 = 9784651;
	unsigned int	u = -5;
	int	*ptr;
	int count;
	int count2;

	count = 0;
	count2 = 0;
	ptr = malloc(sizeof(long));
	ft_printf("ft_printf :\n");
	count += ft_printf("asdfghjk  %%   %c   %s\n", c, str);
	count += ft_printf("%i   %d\n", n, n2);
	count += ft_printf("x : %x\nX : %X\n%u\n", x, x2, u);
	count += ft_printf("ptr : %p\n", ptr);
	ft_printf("printf :\n");
	count2 += printf("asdfghjk  %%   %c   %s\n", c, str);
	count2 += printf("%i   %d\n", n, n2);
	count2 += printf("x : %x\nX : %X\n%u\n", x, x2, u);
	count2 += printf("ptr : %p\n", ptr);
	free(ptr);
//	count += ft_printf("%w  %d\n", 12);
	printf("mon count = %d \nle vrai count = %d", count, count2);
	return (0);
}
