#include "minirt.h"

t_object	*add_object(t_object *object_node)
{
	t_object *new;

	new = malloc(sizeof(t_object));
	new->next = NULL;
	new->type = NONE;
	new->cached_transform = NULL;
	if (object_node)
	{
		while (object_node)
		{
			if (!(object_node->next))
			{
				object_node->next = new;
				break ;
			}
			object_node = object_node->next;
		}
	}
	else
		object_node = new;
	return (object_node);
}

/// @brief Check if the arg provided as parameter is of the right format (.rt file) and if it exists.
/// @param argc 
/// @param argv 
/// @return -1 if error, file descriptor is success
int	check_args(int argc, char **argv)
{
	int		fd;
	char	*file_extension;

	if (argc != 2)
	{
		ft_putstr_fd("Please enter the correct arguments!\n\n./minirt path_to_.rt_file\n", 2);
		fd = -1;
		return (fd);
	}
	file_extension = ft_strrchr(argv[1], '.');
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("Could't open file %s!\n", argv[1]), fd);
	else if (ft_strncmp(file_extension, ".rt", 3))
		return (printf("Please enter a .rt file!\n"));
	else if (fd && !ft_strncmp(file_extension, ".rt", 3))
		return (fd);
	else
		return (printf("Error occured during parsing!\n"));
}

void	fill_structs(t_scene *scene, char **args)
{
	printf("%s\n", args[0]);
	if (!ft_strncmp(args[0], "A", 2))
		fill_ambient(args, scene);
	else if (!ft_strncmp(args[0], "C", 2))
		fill_camera(args, scene);
	else if (!ft_strncmp(args[0], "L", 2))
		fill_light(args, scene);
	else if (!ft_strncmp(args[0], "sp", 3) || !ft_strncmp(args[0], "pl", 3)
		|| !ft_strncmp(args[0], "cy", 3))
	{
		scene->num_objects++;
		if (!ft_strncmp(args[0], "sp", 3))
			fill_sphere(args, add_object(scene->objects));
		else if (!ft_strncmp(args[0], "cy", 3))
			fill_cylinder(args, add_object(scene->objects));
		 else if (!ft_strncmp(args[0], "pl", 3))
		 	fill_plane(args, add_object(scene->objects));
	}
	else
		return (printf("Error during parsing!\n"), exit(1));
}

static void print_args(t_scene *scene)
{
	printf("camera pos x = %f\n", scene->camera->position.x);
	printf("camera pos y = %f\n", scene->camera->position.y);
	printf("camera pos z = %f\n", scene->camera->position.z);

	printf("camera orientation x = %f\n", scene->camera->orientation.x);
	printf("camera orientation y = %f\n", scene->camera->orientation.y);
	printf("camera orientation z = %f\n", scene->camera->orientation.z);

	printf("sphere pos x = %f\n", scene->objects->position.x);
	printf("sphere pos y = %f\n", scene->camera->position.y);
	printf("sphere pos z = %f\n", scene->camera->position.z);
	printf("sphere radius x = %f\n", scene->objects->radius);

	printf("fov = %d\n", scene->camera->fov);
}

/// @brief Main parsing handling function.
/// @param argc 
/// @param argv 
/// @return 
int	parse_file(int argc, char **argv, t_scene *scene)
{
	char	*line;
	char	**args_line;
	int		fd;

	fd = check_args(argc, argv);
	if (fd <= 0)
		clean_exit(scene, NULL);
	line = get_next_line(fd);
	while (line)
	{
		args_line = ft_split_multiple(line, " \t");
		fill_structs(scene, args_line);
		line = get_next_line(fd);
		while (line && *line == '\n')
			line = get_next_line(fd);
		free_array(args_line, arr_len(args_line));
	}
	if (!scene->num_objects)
		return (ft_putstr_fd("No objects to draw!\n", 2), 1);
	print_args(scene);
	return (0);
}
