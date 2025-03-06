/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:57:59 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/03/06 12:20:45 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	init(&scene);
	if (parse_file(argc, argv, &scene))
		return (clean_exit(&scene, "Error parsing file!\n"), 0);
	setup_hooks(&scene);
	render_img(&scene);
	mlx_loop(scene.mlx);
	clean_exit(&scene, NULL);
}
