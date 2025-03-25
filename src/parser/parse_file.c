/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:11 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/25 11:53:56 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*add_object(t_object **object_node)
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
	if (!file_extension)
		return (printf("Please enter a .rt file!\n"), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (printf("Could't open file %s!\n", argv[1]), fd);
	else if (ft_strncmp(file_extension, ".rt", 4))
		return (printf("Please enter a .rt file!\n"), -1);
	else if (fd && !ft_strncmp(file_extension, ".rt", 4))
		return (fd);
	else
		return (printf("Error occured during parsing!\n"));
}

static int	check_all_structs(t_scene *scene)
{
	if (scene->light->ambient_set == false || scene->light->light_set == false)
		return (1);
	if (scene->camera->cam_set == false)
		return (1);
	return (0);
}

static int	read_lines(char *line, char **args_line, t_scene *scene, int fd)
{
	int flag;

	flag = 0;
	while (line)
	{
		args_line = ft_split_multiple(line, " \t");
		if (fill_structs(scene, args_line) == -1)
			flag = 1;
		line = get_next_line(fd);
		while (line && *line == '\n')
		{
			free(line);
			line = get_next_line(fd);
		}
		free_array(args_line, arr_len(args_line));
	}
	return (flag);
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

	args_line = NULL;
	fd = check_args(argc, argv);
	if (fd <= 0)
		clean_exit(scene, NULL);
	line = get_next_line(fd);
	if (read_lines(line, args_line, scene, fd))
		return (1);
	if (!scene->num_objects)
		clean_exit(scene, "No objects to draw!\n");
	if (check_all_structs(scene))
		clean_exit(scene, "Incomplete world description!\n");
	return (0);
}
