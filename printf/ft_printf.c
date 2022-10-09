/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:21:10 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/09 03:16:12 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	arg;

	i = 0;
	va_start(arg, 0);
	while (s[i] != '%' && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	va_arg(arg, int);
	if (s[i] == '%')
	{
		i++;
		if (s[i] == 'c')
		{
			write(1, "ui\n", 3);
			write(1, &arg, 1);
		}
/*		if (s[i] == 's')
			ft_putstr(arg);
//		if (s[i] == 'p')
		if (s[i] == 'i' || s[i] == 'd')
			ft_putnbr_base(arg, "0123456789");
//		if (s[i] == 'u')
//
		if (s[i] == 'x')
			ft_putnbr_base(arg, "0123456789abcdef");
		if (s[i] == 'X')
			ft_putnbr_base(arg, "0123456789ABCDEF");
		if (s[i] == '%')
			write (1, "%", 1);
*/	}
	va_end(arg);
	return (0);
}

int	main()
{
	char	c = 'z';
	ft_printf("asdfghjk   %c", c);
	return (0);
}
