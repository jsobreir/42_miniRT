/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:36:36 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/05 19:58:57 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadecimal(unsigned long nbr, char *base)
{
	int		len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_puthexadecimal(nbr / 16, base);
		len += ft_puthexadecimal(nbr % 16, base);
	}
	else
		len += write(1, &base[nbr], 1);
	return (len);
}

int	ft_putpointer(unsigned long nbr)
{
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = 0;
	if (!nbr)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		len += ft_puthexadecimal(nbr, base);
	}
	return (len);
}
