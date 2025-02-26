/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:53 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:57:54 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/// @brief Initialize the structs.
/// @param scene 
void	init_vars(t_scene *scene)
{
	scene->mlx = NULL;
	scene->mlx_win = NULL;
	scene->img.img = NULL;
	scene->mlx = mlx_init();
	if (scene->mlx == NULL)
	{
		ft_putstr_fd("Error initializing MiniLibX\n", 2);
		exit(EXIT_FAILURE);
	}
	scene->objects = NULL;
	scene->num_objects = 0;
	scene->camera = malloc(sizeof(t_camera));
	scene->light = malloc(sizeof(t_light));
	scene->light->ambient_set = false;
	scene->light->light_set = false;
	scene->camera->cam_set = false;
}

/// @brief Initiallize mlx.
/// @param scene 
void	init(t_scene *scene)
{
	init_vars(scene);
	scene->mlx_win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, "MiniRT");
	if (scene->mlx_win == NULL)
	{
		ft_putstr_fd("Error creating window\n", 2);
		return ;
	}
	scene->img.img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	if (scene->img.img == NULL)
	{
		ft_putstr_fd("Error creating image\n", 2);
		return ;
	}
	scene->img.addr = mlx_get_data_addr(scene->img.img,
			&scene->img.bpp, &scene->img.line_len, &scene->img.endian);
	if (scene->img.addr == NULL)
	{
		ft_putstr_fd("Error getting data address\n", 2);
		mlx_destroy_image(scene->mlx, scene->img.img);
		mlx_destroy_window(scene->mlx, scene->mlx_win);
		return ;
	}
}

void	init_intersections(t_intersections *inter)
{
	(*inter).t[0] = INFINITY;
	(*inter).t[1] = INFINITY;
	(*inter).next = NULL;
	(*inter).object = NULL;
}
