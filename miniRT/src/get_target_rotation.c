/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:20:45 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/17 15:04:08 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	add_matrix4(t_matrix4 a, t_matrix4 b)
{
	return (matrix4(add_tup4(a.t[0], b.t[0]),
			add_tup4(a.t[1], b.t[1]),
			add_tup4(a.t[2], b.t[2]),
			add_tup4(a.t[3], b.t[3])));
}

t_matrix4	scale_matrix(t_matrix4 a, float scalar)
{
	return (matrix4(multiply_tup4(a.t[0], scalar),
			multiply_tup4(a.t[1], scalar),
			multiply_tup4(a.t[2], scalar),
			multiply_tup4(a.t[3], scalar)));
}

t_matrix4	skew_symetric(t_tup4 axis)
{
	return (matrix4(tup4(0, -axis.z, axis.y, 0),
			tup4(axis.z, 0, -axis.x, 0),
			tup4(-axis.y, axis.x, 0, 0),
			tup4(0, 0, 0, 1)));
}

t_matrix4	get_target_rotation(t_tup4 target_y_vec)
{
	t_tup4		rotation_axis;
	float		rotation_angle;
	t_matrix4	skew_sym;
	t_matrix4	out;

	rotation_axis = cross(vector(0, 1, 0), target_y_vec);
	rotation_angle = acos(ft_clamp(dot(vector(0, 1, 0), target_y_vec), -1, 1));
	skew_sym = skew_symetric(rotation_axis);
	out = add_matrix4(add_matrix4(identity_matrix4(),
				scale_matrix(skew_sym, sin(rotation_angle))),
			scale_matrix(multiply_matrix4(skew_sym, skew_sym),
				1 - cos(rotation_angle)));
	out.e[3][3] = 1;
	return (out);
}
