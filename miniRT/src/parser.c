/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:22:13 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/17 19:39:19 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_line(char *line, t_root *r)
{
	int		id;
	char	**elements;

	elements = ft_split(line, ' ');
	if (!elements)
		return (1);
	id = get_id(elements[0]);
	id = is_duplicate(id);
	if (id == AMBIENT)
		id = parse_ambient(elements, r);
	else if (id == CAMERA)
		id = parse_camera(elements, r);
	else if (id == LIGHT)
		id = parse_light(elements, r);
	else if (id == SPHERE)
		id = parse_sphere(elements, r);
	else if (id == PLANE)
		id = parse_plane(elements, r);
	else if (id == CYLINDER)
		id = parse_cylinder(elements, r);
	else
		id = 1;
	ft_matrix_free((void ***)&elements);
	return (id);
}

char	*line_loop(char *line, int fd, t_root *r)
{
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (*line && parse_line(line, r) != 0)
		{
			free_world(r->world);
			exit_parser(line, fd, MISCONFIG_MSG);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	parse_config_file(char *filename, t_root *r)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(FILE_ERROR_MSG, 2);
		free_world(r->world);
		exit(1);
	}
	line = get_next_line(fd);
	line = line_loop(line, fd, r);
	free(line);
	if (!r->world->camera)
	{
		free_world(r->world);
		exit_parser(line, fd, MISCONFIG_MSG);
	}
	close(fd);
}
