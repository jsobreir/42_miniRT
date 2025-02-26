#include "minirt.h"

void	fill_ambient(char **args, t_scene *scene)
{
	char	**sp;

	scene->light->ambient_set = true;
	scene->light->ambient_lighting_ratio = ft_atof1(args[1]);
	sp = ft_split(args[2], ',');
	set_color(&scene->light->ambient_color_rgb, ft_atoi(sp[0]),
		ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
}

void	fill_light(char **args, t_scene *scene)
{
	char	**sp;

	scene->light->light_set = true;
	sp = ft_split(args[1], ',');
	scene->light->position.x = ft_atof1(sp[0]);
	scene->light->position.y = ft_atof1(sp[1]);
	scene->light->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	scene->light->brightness = ft_atof1(args[2]);
	sp = ft_split(args[3], ',');
	set_color(&scene->light->color_rgb, ft_atoi(sp[0]),
		ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
}

void	fill_camera(char **args, t_scene *scene)
{
	char	**sp;

	scene->camera->cam_set = true;
	sp = ft_split(args[1], ',');
	scene->camera->position.x = ft_atof1(sp[0]);
	scene->camera->position.y = ft_atof1(sp[1]);
	scene->camera->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[2], ',');
	scene->camera->orientation.x = ft_atof1(sp[0]);
	scene->camera->orientation.y = ft_atof1(sp[1]);
	scene->camera->orientation.z = ft_atof1(sp[2]);
	scene->camera->orientation = normalize(&scene->camera->orientation);
	free_array(sp, arr_len(sp));
	scene->camera->fov = ft_atoi(args[3]);
}
