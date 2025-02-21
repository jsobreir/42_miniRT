/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrices2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:03:00 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/08/31 14:35:38 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

t_matrix4	rotation_x(float r)
{
	return (matrix4(tup4(1, 0, 0, 0),
			tup4(0, cos(r), -sin(r), 0),
			tup4(0, sin(r), cos(r), 0),
			tup4(0, 0, 0, 1)));
}

t_matrix4	rotation_y(float r)
{
	return (matrix4(tup4(cos(r), 0, sin(r), 0),
			tup4(0, 1, 0, 0),
			tup4(-sin(r), 0, cos(r), 0),
			tup4(0, 0, 0, 1)));
}

t_matrix4	rotation_z(float r)
{
	return (matrix4(tup4(cos(r), -sin(r), 0, 0),
			tup4(sin(r), cos(r), 0, 0),
			tup4(0, 0, 1, 0),
			tup4(0, 0, 0, 1)));
}
