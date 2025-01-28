/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:19:34 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/28 14:33:31 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	point_on_vec3(float t, t_vec3 *vector)
{
	t_point3	ret;
	*vector = normalize(vector);
	ret.x =vector->x * t;
	ret.y =vector->y * t;
	ret.z =vector->z * t;
	return (ret);
}

t_vec3	fill_vec3(t_vec3 *vector, float x, float y, float z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (*vector);
}
