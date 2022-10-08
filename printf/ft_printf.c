/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:21:10 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/05 20:45:17 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *s, ...)
{
	int	i;

	i = 0;
	while (s[i] != '%' && s[i])
		i++;
	if (s[i] == '%')
	{
		i++;
		if (c)
			putchar
		if (s)
			putstr
		if (p)
			pointeur en hexa ()
		if (d)
			float base 10
		if (i)
			int base 10
		if (u)
			comme d mais unsigned
		if (x)
			hexa lettres minuscules
		if (X)
			hexa lettres maj
		if (%)
			write(1, "%", 1);
	}
	else
		putstr chaine de base
	return (0);
}
