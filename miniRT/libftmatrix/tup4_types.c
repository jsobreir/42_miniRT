/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tup4_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:09:24 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/11 09:13:35 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

t_tup4	point(float x, float y, float z)
{
	return (tup4(x, y, z, TPOINT));
}

t_tup4	vector(float x, float y, float z)
{
	return (tup4(x, y, z, TVECTOR));
}

t_tup4	color(float x, float y, float z)
{
	return (tup4(x, y, z, TCOLOR));
}

t_tup4	invalid_tup4(void)
{
	return (tup4(0, 0, 0, TINVALID));
}
