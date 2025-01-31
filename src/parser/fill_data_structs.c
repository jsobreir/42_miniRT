#include "minirt.h"

void	fill_ambient(char **args, t_scene *scene)
{
	char	**sp;

	scene->light->brightness = ft_atof1(args[1]);;
	sp = ft_split(args[2], ',');
	set_color(&scene->light->ambient_color_rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));
}

void	fill_light(char **args, t_scene *scene)
{
	char	**sp;

	sp = ft_split(args[1], ',');
	scene->light->position.x = ft_atof1(sp[0]);
	scene->light->position.y = ft_atof1(sp[1]);
	scene->light->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	scene->light->brightness = ft_atof1(args[2]);
	sp = ft_split(args[3], ',');
	set_color(&scene->light->color_rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	free_array(sp, arr_len(sp));

}

void	fill_camera(char **args, t_scene *scene)
{
	char	**sp;

	sp = ft_split(args[1], ',');
	scene->camera->position.x = ft_atof1(sp[0]);
	scene->camera->position.y = ft_atof1(sp[1]);
	scene->camera->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sp = ft_split(args[2], ',');
	scene->camera->orientation.x = ft_atof1(sp[0]);
	scene->camera->orientation.y = ft_atof1(sp[1]);
	scene->camera->orientation.z = ft_atof1(sp[2]);
	normalize(&scene->camera->orientation);
	free_array(sp, arr_len(sp));
	scene->camera->fov = ft_atoi(args[3]);
}

void	fill_sphere(char **args, t_object *sphere)
{
	char	**sp;
	int		i;

	i = 0;
	sphere->type = SPHERE;
	sp = ft_split(args[1], ',');
	sphere->position.x = ft_atof1(sp[0]);
	sphere->position.y = ft_atof1(sp[1]);
	sphere->position.z = ft_atof1(sp[2]);
	free_array(sp, arr_len(sp));
	sphere->radius = ft_atof1(args[2]) / 2;
	sp = ft_split(args[3], ',');
	set_color(&sphere->rgb, ft_atoi(sp[0]), ft_atoi(sp[1]), ft_atoi(sp[2]));
	printf("object color = %f\n", sphere->rgb.r);
	free_array(sp, arr_len(sp));
}