/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:18:14 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/17 16:19:40 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ambient(char **line, t_root *r)
{
	float	ratio;
	t_tup4	color;

	if (ft_arr2dsize((void **)line) != 3)
		return (1);
	if (!ft_isstr_float(line[1]))
		return (1);
	ratio = ft_atof(line[1]);
	if (ratio < 0 || ratio > 1)
		return (1);
	color = get_color(line[2]);
	if (color.w == TINVALID)
		return (1);
	r->world->ambient.ratio = ratio;
	r->world->ambient.color = color;
	return (0);
}

int	parse_camera(char **line, t_root *r)
{
	t_tup4	view_point;
	t_tup4	axis;
	int		fov;
	t_tup4	upv;

	if (ft_arr2dsize((void **)line) != 4)
		return (1);
	view_point = ft_atotup(line[1], TPOINT);
	axis = ft_atotup(line[2], TVECTOR);
	if (view_point.w == TINVALID || axis.w == TINVALID
		|| !ft_isstr_int(line[3]))
		return (1);
	fov = ft_atoi(line[3]);
	if (!(fov >= 0 && fov <= 180) || !tup_in_range(axis, -1, 1))
		return (1);
	axis = normalize(axis);
	r->world->camera = camera(CANVAS_WIDTH, CANVAS_HEIGHT,
			(fov * (M_PI / 180)));
	upv = vector(0, 1, 0);
	if (tup4cmp(axis, vector(0, 1, 0))
		|| tup4cmp(axis, vector(0, -1, 0)))
		upv = vector(0, 0, 1);
	r->world->camera->transform = view_transform(view_point, axis,
			upv);
	return (0);
}

int	parse_light(char **line, t_root *r)
{
	t_tup4	point;
	float	bright;
	t_tup4	color;

	if (ft_arr2dsize((void **)line) != 4)
		return (1);
	point = ft_atotup(line[1], TPOINT);
	if (point.w == TINVALID || !ft_isstr_float(line[2]))
		return (1);
	bright = ft_atof(line[2]);
	color = get_color(line[3]);
	if (color.w == TINVALID || !(bright >= 0 && bright <= 1))
		return (1);
	color = multiply_tup4(color, bright);
	r->world->light = point_light(point, color);
	return (0);
}
