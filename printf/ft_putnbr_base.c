/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:29:19 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/09 02:33:07 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_base(char *base)
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

void	ft_putnbr_base(int n, char *base)
{
	int	base_len;
	int	last_nb;

	base_len = test_base(base);
	if (base_len < 2)
		return ;
	if (n < 0)
		write(1, "-", 1);
	last_nb = n % base_len;
	n = n / base_len;
	if (n < 0)
		n *= -1;
	if (n > 0)
		ft_putnbr_base(n, base);
	if (last_nb < 0)
		last_nb *= -1;
	write(1, &base[last_nb], 1);
}
