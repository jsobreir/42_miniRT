/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:35:33 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/17 19:06:02 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned char	float_to_shade(float color_strength)
{
	return ((unsigned char)ft_clamp((int)(color_strength * 255.0),
		0, 255));
}

int	tuple_to_color(t_tup4 tup4)
{
	return (float_to_shade(tup4.r) << 16
		| float_to_shade(tup4.g) << 8 | float_to_shade(tup4.b));
}

t_tup4	color_at(t_world *w, t_ray r)
{
	t_intersection	*xs;
	t_intersection	*hit_int;
	t_comps			comps;

	xs = intersect_world(w, r);
	hit_int = hit(xs);
	if (!hit_int)
		return (color(0, 0, 0));
	comps = prepare_computations(hit_int, r);
	intclear(&xs);
	return (shade_hit(w, comps));
}

float	shade_to_float(unsigned char shade)
{
	float	shadef;

	shadef = (float)shade;
	return (shadef / 255.0);
}
