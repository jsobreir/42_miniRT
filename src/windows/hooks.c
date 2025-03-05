/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:50 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/05 17:24:26 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int free_exit(t_scene *scene)
{
	clean_exit(scene, NULL);
	return (0);
}

void	setup_hooks(t_scene *scene)
{
	mlx_hook(scene->mlx_win, 17, 0, free_exit, scene);
	mlx_key_hook(scene->mlx_win, handle_keys, scene);
}

