/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:33 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:57:34 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		i++;
	}
	return (i);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = ((y * img->line_len) + (x * (img->bpp / 8)));
	*(unsigned int *)(img->addr + offset) = color;
}

void	print_vec3(t_vec3 *vector)
{
	printf("%f\n", vector->x);
	printf("%f\n", vector->y);
	printf("%f\n", vector->z);
}

static void	init_vars_atof(t_atof *a, char *nbr)
{
	a->frac_part = 0.1;
	a->int_part = 0;
	a->frac_pow = 1;
	a->neg = 1;
	a->int_part = ft_atoi(nbr);
}

float	ft_atof1(char *nbr)
{
	t_atof	a;

	init_vars_atof(&a, nbr);
	if (nbr[0] == '-')
		a.neg = -1;
	while (*nbr && *nbr != '.')
	{
		if (!nbr)
			return ((float) a.int_part);
		nbr++;
	}
	if (nbr && *nbr && *nbr == '.')
		nbr++;
	else
		return ((float) a.int_part);
	a.frac_part = ft_atoi(nbr);
	while (nbr && *nbr && (*nbr >= '0' && *nbr <= '9'))
	{
		nbr++;
		a.frac_pow *= 10;
	}
	a.ret = a.int_part + (a.frac_part / a.frac_pow * a.neg);
	return (a.ret);
}
