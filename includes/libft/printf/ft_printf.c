/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:28:32 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/04 16:55:47 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		len += ft_putpointer(va_arg(args, unsigned long));
	if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		len += ft_putunsignednbr(va_arg(args, unsigned int));
	if (c == '%')
		len += write(1, &c, 1);
	if (c == 'x')
		len += ft_puthexadecimal(va_arg(args, unsigned int),
				"0123456789abcdef");
	if (c == 'X')
		len += ft_puthexadecimal(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	if (c == 'f')
		len += ft_putfloat(va_arg(args, double), 6);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			len += ft_print_format(*(++format), args);
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
