/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlenbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:00:13 by lumaret           #+#    #+#             */
/*   Updated: 2024/01/06 13:51:36 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		if (n == -2147483648)
		{
			i += ft_putchar('2');
			n %= 1000000000;
		}
		i += ft_putnbr(-n);
	}
	else if (n >= 0 && n < 10)
	{
		i += ft_putchar(n + '0');
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	ft_uitoa(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += ft_uitoa(nbr / 10);
		count += ft_putchar(nbr % 10 + '0');
	}
	else
		count += ft_putchar(nbr + '0');
	return (count);
}

int	ft_putunsigned(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	else
	{
		len += ft_uitoa(n);
	}
	return (len);
}
