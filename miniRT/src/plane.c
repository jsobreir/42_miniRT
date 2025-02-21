/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:18:40 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/12 19:21:31 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*plane(void)
{
	t_plane	*p;

	p = (t_plane *)ft_calloc(1, sizeof(t_plane));
	p->type = PLANE;
	p->transform = identity_matrix4();
	p->material = material();
	p->normal = tup4(0, 1, 0, TVECTOR);
	return (p);
}

t_intersection	*plane_intersect(t_plane *plane, t_ray ray)
{
	float			i_value;
	t_intersection	*xs;

	if (fabsf(ray.direction.y) < EPSILON)
		return (NULL);
	i_value = -ray.origin.y / ray.direction.y;
	xs = NULL;
	int_add_back(&xs, intersection(i_value, plane));
	return (xs);
}
