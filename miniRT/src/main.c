/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:07:10 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/17 19:04:11 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point_light	point_light(t_tup4 position, t_tup4 intensity)
{
	t_point_light	out;

	out.position = position;
	out.intensity = intensity;
	return (out);
}

t_material	material(void)
{
	t_material	out;

	out.color = color(1, 1, 1);
	out.diffuse = 0.9;
	out.specular = 0.9;
	out.shininess = 200.0;
	return (out);
}

void	select_object(t_obj_type type, t_root *r)
{
	if (r->current_object == LIGHT)
		r->world->light.intensity = multiply_tup4(
				r->world->light.intensity, 1.0 / 2.0);
	else if (r->current_object == SHAPE && r->current_shape)
		((t_shape *)r->current_shape->content)->material.diffuse *= 1.0 / 2.0;
	r->current_object = type;
	if (type == LIGHT)
		r->world->light.intensity = multiply_tup4(
				r->world->light.intensity, 2.0);
	else if (type == SHAPE)
	{
		if (r->current_shape)
			r->current_shape = r->current_shape->next;
		else
			r->current_shape = r->world->objects;
		if (r->current_shape)
			((t_shape *)r->current_shape->content)->material.diffuse *= 2.0;
	}
	render(r);
}

int	key_hook(int keycode, t_root *r)
{
	if (keycode == 65307)
		clean_exit(r, 0);
	else if (keycode == XK_c)
		select_object(CAMERA, r);
	else if (keycode == XK_l)
		select_object(LIGHT, r);
	else if (keycode == XK_s)
		select_object(SHAPE, r);
	else if (keycode == XK_Left)
	{
		if (r->transf_type <= 0)
			r->transf_type = 10;
		r->transf_type = (r->transf_type - 1);
		print_transform(r);
	}
	else if (keycode == XK_Right)
	{
		r->transf_type = (r->transf_type + 1) % TRANSF_TYPE_AM;
		print_transform(r);
	}
	else if (keycode == XK_Up)
		apply_transformation(r, 1);
	else if (keycode == XK_Down)
		apply_transformation(r, -1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_root	r;
	char	*extension;

	if (argc != 2)
		return (ft_putstr_fd(WRONG_USAGE_MSG, 2), 1);
	extension = ft_substr(argv[1], ft_strlen(argv[1]) - 3, 3);
	if (strcmp(extension, ".rt") != 0)
		return (free(extension), ft_putstr_fd(FILE_EXT_MSG, 2), 1);
	free(extension);
	r.world = world();
	r.transf_type = ROTATEX;
	r.current_object = INVALID_OBJ;
	r.current_shape = NULL;
	parse_config_file(argv[1], &r);
	r.mlx = mlx_init();
	r.win = mlx_new_window(r.mlx, CANVAS_WIDTH, CANVAS_HEIGHT, WINDOW_TITLE);
	r.canvas = (t_canvas *)ft_calloc(1, sizeof(t_canvas));
	r.canvas->img = mlx_new_image(r.mlx, CANVAS_WIDTH, CANVAS_HEIGHT);
	r.canvas->addr = mlx_get_data_addr(r.canvas->img, &r.canvas->bits_per_pixel,
			&r.canvas->line_length, &r.canvas->endian);
	render(&r);
	mlx_key_hook(r.win, key_hook, &r);
	mlx_hook(r.win, DestroyNotify, 0L, clean_exit, &r);
	mlx_loop(r.mlx);
}
