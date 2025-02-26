#include "minirt.h"

static t_object	*add_object(t_object **object_node)
{
	t_object	*new;
	t_object	*current;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	ft_memset(new, 0, sizeof(t_object));
	new->next = NULL;
	new->type = NONE;
	if (*object_node)
	{
		current = *object_node;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	else
		*object_node = new;
	return (new);
}

/// @brief Check if the arg provided as parameter is 
///of the right format (.rt file) and if it exists.
/// @param argc 
/// @param argv 
/// @return -1 if error, file descriptor is success
int	check_args(int argc, char **argv)
{
	int		fd;
	char	*file_extension;

	if (argc != 2)
	{
		ft_putstr_fd("Please enter the correct arguments!\n\n"
			"./minirt path_to_.rt_file\n", 2);
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

static void	fill_structs(t_scene *scene, char **args)
{
	t_object	*new_obj;

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
		new_obj = add_object(&scene->objects);
		if (!ft_strncmp(args[0], "sp", 3))
			fill_sphere(args, new_obj);
		else if (!ft_strncmp(args[0], "cy", 3))
			fill_cylinder(args, new_obj);
		else if (!ft_strncmp(args[0], "pl", 3))
			fill_plane(args, new_obj);
	}
	else
		return ;
}

static int	check_all_structs(t_scene *scene)
{
	if (scene->light->ambient_set == false || scene->light->light_set == false)
		return (1);
	if (scene->camera->cam_set == false)
		return (1);
	return (0);
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
		{
			free(line);
			line = get_next_line(fd);
		}
		free_array(args_line, arr_len(args_line));
	}
	if (!scene->num_objects)
		return (ft_putstr_fd("No objects to draw!\n", 2), 1);
	if (check_all_structs(scene))
		return (ft_putstr_fd("Incomplete world description!\n", 2), 1);
	return (0);
}
