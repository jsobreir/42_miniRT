/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:28:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/07/04 16:50:25 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (nbr < 0)
	{
		len += write(1, "-", 1);
		len += ft_putnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else
	{
		nbr += '0';
		len += write(1, &nbr, 1);
	}
	return (len);
}

int	ft_putunsignednbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else
	{
		nbr += '0';
		len += write(1, &nbr, 1);
	}
	return (len);
}

int	ft_putfloat(double number, int precision)
{
	int		int_part;
	double	frac_part;
	int		len;
	int		digit;
	char	c;

	len = 0;
	if (number < 0)
	{
		number *= -1;
		len += write(1, "-", 1);
	}
	int_part = (int)number;
	frac_part = number - int_part;
	len += ft_putnbr(int_part);
	len += write(1, ".", 1);
	while (precision-- && precision > 0)
	{
		frac_part *= 10;
		digit = (int)frac_part;
		c = digit + '0';
		len += write(1, &c, 1);
		frac_part -= digit;
	}
	return (len);
}
