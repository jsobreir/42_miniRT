/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:09 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/24 14:25:18 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	fill_objects(t_scene *scene, char **args, t_object *obj)
{
	if (!ft_strncmp(args[0], "sp", 3))
	{
		if (fill_sphere(scene, args, obj) == -1)
			return (-1);
	}
	else if (!ft_strncmp(args[0], "cy", 3))
	{
		if (fill_cylinder(scene, args, obj) == -1)
			return (-1);
	}
	else if (!ft_strncmp(args[0], "pl", 3))
	{
		if (fill_plane(args, obj) == -1)
			return (-1);
	}
	return (0);
}

int	fill_sphere(t_scene *scene, char **args, t_object *sphere)
{
	char	**sp;

	sphere->type = SPHERE;
	if (!args[1] || !args[2] || !args[3])
		return (-1);
	sp = ft_split(args[1], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2])
		return (-1);
	sphere->position.x = ft_atof1(sp[0]);
	sphere->position.y = ft_atof1(sp[1]);
	sphere->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sphere->radius = ft_atof1(args[2]) / 2;
	sp = ft_split(args[3], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || *sp[2] == '\n')
		return (-1);
	set_color(&sphere->rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
	sphere->light_inside = light_inside(sphere, scene);
	return (0);
}

static void	fill_vec(t_vec3 *vec, char **sp)
{
	vec->x = ft_atof1(sp[0]);
	vec->y = ft_atof1(sp[1]);
	vec->z = ft_atof1(sp[2]);
}

int	fill_cylinder(t_scene *scene, char **args, t_object *cylinder)
{
	char	**sp;

	cylinder->type = CYLINDER;
	if (!args[1] || !args[2] || !args[3] || !args[4])
		return (-1);
	sp = ft_split(args[1], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2])
		return (-1);
	fill_vec(&cylinder->position, sp);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[2], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2])
		return (-1);
	fill_vec(&cylinder->orientation, sp);
	free_array(sp, arr_len(sp));
	cylinder->radius = ft_atof1(args[3]) / 2.f;
	cylinder->height = ft_atof1(args[4]);
	sp = ft_split(args[5], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || *sp[2] == '\n')
		return (-1);
	set_color(&cylinder->rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	cylinder->orientation = normalize(&cylinder->orientation);
	free_array(sp, arr_len(sp));
	cylinder->light_inside = light_inside(cylinder, scene);
	return (0);
}

int	fill_plane(char **args, t_object *plane)
{
	char	**sp;

	plane->type = PLANE;
	if (!args[1] || !args[2] || !args[3])
		return (-1);
	sp = ft_split(args[1], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2])
		return (-1);
	fill_vec(&plane->position, sp);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[2], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2])
		return (-1);
	fill_vec(&plane->orientation, sp);
	plane->orientation = normalize(&plane->orientation);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[3], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || *sp[2] == '\n')
		return (-1);
	set_color(&plane->rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
	plane->light_inside = false;
	return (0);
}
