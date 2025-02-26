/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:38 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:57:39 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	clean_objects(t_object *obj)
{
	t_object	*temp;

	while (obj)
	{
		temp = obj;
		if (obj->cached_transform)
			mtx_free(obj->cached_transform);
		obj = obj->next;
		free(temp);
	}
}

static void	free_everything(t_scene *scene)
{
	if (scene->objects)
		clean_objects(scene->objects);
	if (scene->camera)
		free(scene->camera);
	if (scene->light)
		free(scene->light);
	if (scene->img.img)
		mlx_destroy_image(scene->mlx, scene->img.img);
	if (scene->mlx_win && scene->mlx)
		mlx_destroy_window(scene->mlx, scene->mlx_win);
	if (scene->mlx)
	{
		mlx_loop_end(scene->mlx);
		mlx_destroy_display(scene->mlx);
		free(scene->mlx);
	}
}

/// @brief Window clean exit.
/// @param scene 
/// @return 
int	clean_exit(t_scene *scene, char *msg)
{
	if (!scene)
		return (1);
	free_everything(scene);
	if (!msg)
		ft_putstr_fd("Exiting program cleanly.\n", 1);
	else
		ft_putstr_fd(msg, 2);
	if (!msg)
		exit(0);
	else
		exit(1);
	return (0);
}

int	handle_keys(int key, t_scene *scene)
{
	if (key == XK_Escape)
	{
		clean_exit(scene, NULL);
		return (0);
	}
	return (0);
}

int	free_array(char	**arr, int len)
{
	while (len--)
	{
		free(arr[len]);
	}
	free(arr);
	return (0);
}
