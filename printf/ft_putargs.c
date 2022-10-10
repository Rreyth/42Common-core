/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:29:19 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/10 01:33:44 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_baselen(char *base)
{
	int	i;
	int	asc[127];
	int	tmp;

	i = 0;
	while (i <= 127)
	{
		asc[i] = 0;
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		tmp = base[i];
		asc[tmp]++;
		if (asc[tmp] > 1)
			return (0);
		else
			i++;
	}
	return (i);
}

int	ft_putnbr_base(long n, char *base, int count)
{
	long	base_lengh;
	long	last_nb;

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
		count = ft_putnbr_base(n, base, count);
	if (last_nb < 0)
		last_nb *= -1;
	write(1, &base[last_nb], 1);
	count++;
	return (count);
}

int	ft_putstr(char *s)
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
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
