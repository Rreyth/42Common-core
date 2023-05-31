/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:29:19 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/12/05 14:00:04 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_baselen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_base(long n, char *base)
{
	int	base_lengh;
	int	last_nb;
	int	count;

	count = 0;
	base_lengh = ft_baselen(base);
	if (base_lengh < 2)
		return (count);
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
	}
	last_nb = n % base_lengh;
	n = n / base_lengh;
	if (n < 0)
		n *= -1;
	if (n > 0)
		count += ft_putnbr_base(n, base);
	if (last_nb < 0)
		last_nb *= -1;
	write(1, &base[last_nb], 1);
	count++;
	return (count);
}

int	ft_putptr_pf(unsigned long n)
{
	int		last_nb;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	last_nb = n % 16;
	n = n / 16;
	if (n > 0)
		count += ft_putptr_pf(n);
	write(1, &base[last_nb], 1);
	count++;
	return (count);
}

int	ft_putstr_pf(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		i = 6;
	}
	return (i);
}

int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}
