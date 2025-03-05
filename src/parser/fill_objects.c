/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42porto.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:09 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/05 19:18:29 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_sphere(t_scene *scene, char **args, t_object *sphere)
{
	char	**sp;

	sphere->type = SPHERE;
	sp = ft_split(args[1], ',');
	sphere->position.x = ft_atof1(sp[0]);
	sphere->position.y = ft_atof1(sp[1]);
	sphere->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sphere->radius = ft_atof1(args[2]) / 2;
	sp = ft_split(args[3], ',');
	set_color(&sphere->rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
	sphere->light_inside = light_inside(sphere, scene);
}

void	fill_cylinder(t_scene *scene, char **args, t_object *cylinder)
{
	char	**sp;

	cylinder->type = CYLINDER;
	sp = ft_split(args[1], ',');
	cylinder->position.x = ft_atof1(sp[0]);
	cylinder->position.y = ft_atof1(sp[1]);
	cylinder->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[2], ',');
	cylinder->orientation.x = ft_atof1(sp[0]);
	cylinder->orientation.y = ft_atof1(sp[1]);
	cylinder->orientation.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	cylinder->radius = ft_atof1(args[3]) / 2.f;
	cylinder->height = ft_atof1(args[4]);
	sp = ft_split(args[5], ',');
	set_color(&cylinder->rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	cylinder->orientation = normalize(&cylinder->orientation);
	free_array(sp, arr_len(sp));
	cylinder->light_inside = light_inside(cylinder, scene);
}

void	fill_plane(char **args, t_object *plane)
{
	char	**sp;

	plane->type = PLANE;
	sp = ft_split(args[1], ',');
	plane->position.x = ft_atof1(sp[0]);
	plane->position.y = ft_atof1(sp[1]);
	plane->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[2], ',');
	plane->orientation.x = ft_atof1(sp[0]);
	plane->orientation.y = ft_atof1(sp[1]);
	plane->orientation.z = ft_atof1(sp[2]);
	plane->orientation = normalize(&plane->orientation);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[3], ',');
	set_color(&plane->rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
	plane->light_inside = false;
}
