/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:14:06 by lumaret           #+#    #+#             */
/*   Updated: 2024/01/07 15:04:07 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (type == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (type == 'p' || type == 'P')
		count += ft_putptr(va_arg(ap, unsigned long), type);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (type == 'u')
		count += ft_putunsigned(va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_handleptr(va_arg(ap, unsigned int), type);
	else
		count += ft_putchar(type);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += check_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
