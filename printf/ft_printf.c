/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:21:10 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/10 02:44:45 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr != 0)
	{
		count += ft_putstr("0x");
		count += ft_putptr(ptr);
	}
	else
		count += ft_putstr("(nil)");
	return (count);
}

int	ft_launch_print(char c, va_list arg)
{
	int				count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	if (c == 'i' || c == 'd')
		count += ft_putnbr_base(va_arg(arg, int), "0123456789");
	if (c == 'x')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (c == 'u')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
	if (c == 'p')
		count += ft_print_ptr(va_arg(arg, unsigned long));
	if (c == '%')
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && ft_check_flag(s[i + 1], "cspdiuxX%"))
		{
			i++;
			count += ft_launch_print(s[i], arg);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
