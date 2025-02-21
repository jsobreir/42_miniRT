/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:44:27 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/08/31 17:15:32 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

float	magnitude(t_tup4 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w));
}

t_tup4	normalize(t_tup4 a)
{
	return (divide_tup4(a, magnitude(a)));
}

float	dot(t_tup4 a, t_tup4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_tup4	cross(t_tup4 a, t_tup4 b)
{
	return (tup4(a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x, TVECTOR));
}

t_tup4	hadamard(t_tup4 a, t_tup4 b)
{
	return (tup4(a.x * b.x, a.y * b.y, a.z * b.z, TCOLOR));
}
