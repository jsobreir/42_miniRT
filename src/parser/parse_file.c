#include "minirt.h"

/// @brief Check if the arg provided as parameter is of the right format (.rt file) and if it exists.
/// @param argc 
/// @param argv 
/// @return -1 if error, file descriptor is success
int	check_args(int argc, char **argv)
{
	int		fd;
	char	*filename;
	char	*file_extension;

	if (argc != 2)
	{
		printf("Please enter the correct arguments!\n\n./minirt path_to_.rt_file\n");
		fd = -1;
		return (fd);
	}
	file_extension = ft_strrchr(argv[1], ".");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("Could't open file %s!\n", argv[1]), fd);
	else if (ft_strncmp(file_extension, ".rt", 3))
		return (printf("Please enter a .rt file!\n"), -1);
	else if (fd && !ft_strncmp(file_extension, ".rt", 3))
		return (fd);
	else
		return (printf("Error occured during parsing!\n", -1));
}

void	fill_structs(t_scene *scene, char **args)
{
	if (!ft_strncmp(args[0], "A", 2))
		fill_light("A", args, scene);
	else if (!ft_strncmp(args[0], "C", 2))
		fill_camera(args, scene);
	else if (!ft_strncmp(args[0], "L", 2))
		fill_light("L", args, scene);
	else if (!ft_strncmp(args[0], "sp", 3))
		fill_sphere(args, scene);
	else if (!ft_strncmp(args[0], "pl", 3))
		fill_plane(args, scene);
	else if (!ft_strncmp(args[0], "cy", 3))
		fill_cylinder(args, scene);
	else
		return (printf("Error during parsing!\n"), exit(1));
}

/// @brief Main parsing handling function.
/// @param argc 
/// @param argv 
/// @return 
int	parse_file(int argc, char **argv)
{
	char	*line;
	char	**args_line;
	int		fd;
	t_scene	*scene;

	fd = check_args(argc, argv);
	if (fd <= 0)
		clean_exit(scene);
	line = get_next_line(fd);
	while (line)
	{
		args_line = ft_split(line, " ");
		fill_structs(scene, args_line);
		line = get_next_line(fd);
		free_array(args_line, arr_len(args_line));
	}
}
