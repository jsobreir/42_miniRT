/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_structs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:06 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/25 11:57:38 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	fill_structs(t_scene *scene, char **args)
{
	t_object	*new_obj;

	if (fill_them(scene, args) == -1)
		return (-1);
	else if (!ft_strncmp(args[0], "sp", 3) || !ft_strncmp(args[0], "pl", 3)
		|| !ft_strncmp(args[0], "cy", 3))
	{
		scene->num_objects++;
		new_obj = add_object(&scene->objects);
		if (fill_objects(scene, args, new_obj) == -1)
			return (-1);
	}
	return (0);
}

int	fill_them(t_scene *scene, char **args)
{
	if (!ft_strncmp(args[0], "A", 2))
	{
		if (fill_ambient(args, scene) == -1)
			return (-1);
	}
	else if (!ft_strncmp(args[0], "C", 2))
	{
		if (fill_camera(args, scene) == -1)
			return (-1);
	}
	else if (!ft_strncmp(args[0], "L", 2))
	{
		if (fill_light(args, scene) == -1)
			return (-1);
	}
	return (0);
}

int	fill_ambient(char **args, t_scene *scene)
{
	char	**sp;

	if (!args || !args[1] || !args[2])
		return (-1);
	scene->light->ambient_set = true;
	scene->light->amb_ratio = ft_atof1(args[1]);
	sp = ft_split(args[2], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || *sp[2] == '\n')
		return (free_array(sp, arr_len(sp)), -1);
	set_color(&scene->light->ambient_color_rgb, ft_atoi(sp[0]),
		ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
	return (0);
}

int	fill_light(char **args, t_scene *scene)
{
	char	**sp;

	if (!args || !args[1] || !args[2])
		return (-1);
	scene->light->light_set = true;
	sp = ft_split(args[1], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2])
		return (free_array(sp, arr_len(sp)), -1);
	scene->light->position.x = ft_atof1(sp[0]);
	scene->light->position.y = ft_atof1(sp[1]);
	scene->light->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	scene->light->brightness = ft_atof1(args[2]);
	sp = ft_split(args[3], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || *sp[2] == '\n')
		return (free_array(sp, arr_len(sp)), -1);
	set_color(&scene->light->color_rgb, ft_atoi(sp[0]),
		ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
	return (0);
}

int	fill_camera(char **args, t_scene *scene)
{
	char	**sp;

	if (!args || !args[1] || !args[2])
		return (-1);
	scene->camera->cam_set = true;
	sp = ft_split(args[1], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2])
		return (free_array(sp, arr_len(sp)), -1);
	scene->camera->position.x = ft_atof1(sp[0]);
	scene->camera->position.y = ft_atof1(sp[1]);
	scene->camera->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[2], ',');
	if (!sp || !sp[0] || !sp[1] || !sp[2] || *sp[2] == '\n')
		return (free_array(sp, arr_len(sp)), -1);
	scene->camera->orientation.x = ft_atof1(sp[0]);
	scene->camera->orientation.y = ft_atof1(sp[1]);
	scene->camera->orientation.z = ft_atof1(sp[2]);
	scene->camera->orientation = normalize(&scene->camera->orientation);
	free_array(sp, arr_len(sp));
	scene->camera->fov = ft_atoi(args[3]);
	return (0);
}
