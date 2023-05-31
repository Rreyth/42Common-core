/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdhaussy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:59:22 by tdhaussy          #+#    #+#             */
/*   Updated: 2022/10/24 16:41:50 by tdhaussy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

int	main()
{
//	void	*ptr;

//	ptr = -1;
/*	char	c = 'z';
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
	printf("mon count = %d \nle vrai count = %d\n", count, count2);
//	ft_printf("test ft_printf flag invalide : %t , %w\n", x); IGNORE
//	printf("test printf flag invalide : %t , %w\n", x); ERROR
	ft_printf(" %x ", -1);
	printf(" %x ", -1);
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);

//	printf("%s\n", ptr);
//	ft_printf("%s\n", NULL);
//	free(ptr);
	printf("%p\n", (void *) -1);
	count = printf("%p\n", (void *) -1);
	printf("printf : %d\n", count);
	count2 = ft_printf("%p\n", (void *) -1);
	printf("ft_printf : %d\n", count2);
//	printf("LE VRAI \n%p\n%p", ptr, (void *) -1);*/
	ft_printf("%%%c\n", 'h');
	return (0);
}
