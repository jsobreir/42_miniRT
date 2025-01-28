#include "minirt.h"

void	fill_light(char type, char **args, t_scene *scene)
{
	float	num;
	char	**split_commas;

	if (type == "A")
	{
		num = ft_atof(args[1]); //TODO atof that checks if number
		scene->light.ambient_lighting_ratio = num;
		split_commas = ft_split(args[2], ",");
		num = ft_atof(split_commas[0]);
		scene->light.ambient_color_rgb[0] = num;
		num = ft_atof(split_commas[1]);
		scene->light.ambient_color_rgb[1] = num;
		num = ft_atof(split_commas[2]);
		scene->light.ambient_color_rgb[2] = num;
		free_array(split_commas, arr_len(split_commas));
	}
	else if (type == "L")
	{

	}
}