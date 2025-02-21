/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrices1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:55:17 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/08/31 14:36:38 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

t_matrix4	translation(float x, float y, float z)
{
	return (matrix4(tup4(1, 0, 0, x),
			tup4(0, 1, 0, y),
			tup4(0, 0, 1, z),
			tup4(0, 0, 0, 1)));
}

t_matrix4	scaling(float x, float y, float z)
{
	return (matrix4(tup4(x, 0, 0, 0),
			tup4(0, y, 0, 0),
			tup4(0, 0, z, 0),
			tup4(0, 0, 0, 1)));
}

t_matrix4	shearing(t_tup2 x, t_tup2 y, t_tup2 z)
{
	return (matrix4(tup4(1, x.e[0], x.e[1], 0),
			tup4(y.e[0], 1, y.e[1], 0),
			tup4(z.e[0], z.e[1], 1, 0),
			tup4(0, 0, 0, 1)));
}
