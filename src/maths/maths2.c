/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:19:34 by jsobreir          #+#    #+#             */
/*   Updated: 2025/01/16 16:59:50 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	point_on_vec3(float t, t_vec3 *vector)
{
	t_point3	ret;
	*vector = normalize(vector);
	mult_byscalar(vector, t);
	ret.x =vector->x;
	ret.y =vector->y;
	ret.z =vector->z;

	return (ret);
}