/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:37 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:38 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	*calculate_rotation(t_vec3 rotation_axis, float theta)
{
	t_matrix	*skew_sym;
	t_matrix	*skew_sym_squared;
	t_matrix	*rotation;
	t_matrix	*temp;
	t_matrix	*ident;

	skew_sym = mtx_skew_symmetric(rotation_axis);
	skew_sym = mtx_mult_by_float(skew_sym, sinf(theta));
	skew_sym_squared = mtx_skew_symmetric_squared(rotation_axis);
	skew_sym_squared = mtx_mult_by_float(skew_sym_squared, 1 - cosf(theta));
	ident = mtx_identity(4, 4);
	temp = mtx_add(*ident, *skew_sym);
	mtx_free(ident);
	mtx_free(skew_sym);
	rotation = mtx_add(*temp, *skew_sym_squared);
	mtx_free(skew_sym_squared);
	mtx_free(temp);
	rotation->matrix[3][3] = 1.0;
	return (rotation);
}

t_matrix	*rotation_matrix(t_object *obj)
{
	t_vec3		world_up;
	t_vec3		rotation_axis;
	t_vec3		orient;
	t_matrix	*rotation;
	float		theta;

	orient = obj->orientation;
	if (orient.x == 0 && orient.y != 0 && orient.z == 0)
		return (mtx_identity(4, 4));
	fill_vec3(&world_up, 0, 1, 0);
	rotation_axis = cross_product(orient, world_up);
	theta = acosf(dot_product(orient, world_up) / magnitude(orient));
	rotation = calculate_rotation(rotation_axis, theta);
	return (rotation);
}
