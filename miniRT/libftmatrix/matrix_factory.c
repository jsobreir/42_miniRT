/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:55:47 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/08/31 14:39:21 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

t_matrix2	matrix2(t_tup2 x, t_tup2 y)
{
	t_matrix2	out;

	out.t[0] = x;
	out.t[1] = y;
	return (out);
}

t_matrix3	matrix3(t_tup3 x, t_tup3 y, t_tup3 z)
{
	t_matrix3	out;

	out.t[0] = x;
	out.t[1] = y;
	out.t[2] = z;
	return (out);
}

t_matrix4	matrix4(t_tup4 x, t_tup4 y, t_tup4 z, t_tup4 w)
{
	t_matrix4	out;

	out.t[0] = x;
	out.t[1] = y;
	out.t[2] = z;
	out.t[3] = w;
	return (out);
}

t_matrix4	identity_matrix4(void)
{
	return (matrix4(tup4(1, 0, 0, 0),
			tup4(0, 1, 0, 0),
			tup4(0, 0, 1, 0),
			tup4(0, 0, 0, 1)));
}
