/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:34:22 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/13 19:43:10 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_parser(char *line, int fd, char *msg)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_putstr_fd(msg, 2);
	exit(1);
}

t_tup4	ft_atotup(char *str, int type)
{
	t_tup4	result;
	int		i;
	char	**arr2d;

	arr2d = ft_split(str, ',');
	if (ft_arr2dsize((void **)arr2d) != 3)
		return (ft_matrix_free((void ***)&arr2d), invalid_tup4());
	i = -1;
	while (++i < 3)
	{
		if (!ft_isstr_float(arr2d[i]))
			return (ft_matrix_free((void ***)&arr2d), invalid_tup4());
		result.e[i] = ft_atof(arr2d[i]);
	}
	result.w = type;
	ft_matrix_free((void ***)&arr2d);
	return (result);
}

char	get_id(char *first_arg)
{
	if (!first_arg)
		return (INVALID_OBJ);
	if (ft_strncmp(first_arg, "A", 2) == 0)
		return (AMBIENT);
	else if (ft_strncmp(first_arg, "C", 2) == 0)
		return (CAMERA);
	else if (ft_strncmp(first_arg, "L", 2) == 0)
		return (LIGHT);
	else if (ft_strncmp(first_arg, "sp", 3) == 0)
		return (SPHERE);
	else if (ft_strncmp(first_arg, "pl", 3) == 0)
		return (PLANE);
	else if (ft_strncmp(first_arg, "cy", 3) == 0)
		return (CYLINDER);
	return (INVALID_OBJ);
}

t_tup4	get_color(char *colors)
{
	char	**color_arr;
	t_tup4	out;
	int		i;
	int		shade;

	color_arr = ft_split(colors, ',');
	if (ft_arr2dsize((void **)color_arr) != 3)
		return (ft_matrix_free((void ***)&color_arr), invalid_tup4());
	i = -1;
	while (++i < 3)
	{
		if (!ft_isstr_int(color_arr[i]))
			return (ft_matrix_free((void ***)&color_arr), invalid_tup4());
		shade = ft_atoi(color_arr[i]);
		if (shade < 0 || shade > 255)
			return (ft_matrix_free((void ***)&color_arr), invalid_tup4());
		out.e[i] = shade_to_float((unsigned char)shade);
	}
	out.w = TCOLOR;
	ft_matrix_free((void ***)&color_arr);
	return (out);
}

bool	tup_in_range(t_tup4 tup, float rmin, float rmax)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (tup.e[i] < rmin || tup.e[i] > rmax)
			return (false);
	}
	return (true);
}
