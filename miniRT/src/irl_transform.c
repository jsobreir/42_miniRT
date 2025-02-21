/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irl_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:52:18 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/17 17:19:05 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	define_transf_matrix(int transf_type, int change_dir)
{
	t_matrix4	out;

	if (transf_type == ROTATEX)
		out = rotation_x(M_PI / 16);
	else if (transf_type == ROTATEY)
		out = rotation_y(M_PI / 16);
	else if (transf_type == ROTATEZ)
		out = rotation_z(M_PI / 16);
	else if (transf_type == SCALEX)
		out = scaling(1.1, 1, 1);
	else if (transf_type == SCALEY)
		out = scaling(1, 1.1, 1);
	else if (transf_type == SCALEZ)
		out = scaling(1, 1, 1.1);
	else if (transf_type == TRANSLATEX)
		out = translation(1, 0, 0);
	else if (transf_type == TRANSLATEY)
		out = translation(0, 1, 0);
	else if (transf_type == TRANSLATEZ)
		out = translation(0, 0, 1);
	if (change_dir == -1)
		out = invert_matrix4(out);
	return (out);
}

t_matrix4	include_new_transformation(t_matrix4 tr_obj,
	t_matrix4 tr_new, t_transf_type t_type)
{
	t_matrix4	current_translation;

	current_translation = translation(tr_obj.e[0][3],
			tr_obj.e[1][3], tr_obj.e[2][3]);
	tr_obj = multiply_matrix4(invert_matrix4(current_translation), tr_obj);
	if (t_type == SCALEX || t_type == SCALEY || t_type == SCALEZ)
		tr_obj = multiply_matrix4(tr_obj, tr_new);
	else
		tr_obj = multiply_matrix4(tr_new, tr_obj);
	return (multiply_matrix4(current_translation, tr_obj));
}

void	apply_transformation(t_root *r, int change_dir)
{
	t_matrix4	transf_matrix;
	t_shape		*shape;

	if (r->transf_type == NO_TRANSFORM_TYPE)
		return ;
	transf_matrix = define_transf_matrix(r->transf_type, change_dir);
	if (r->current_object == CAMERA)
		r->world->camera->transform = multiply_matrix4(transf_matrix,
				r->world->camera->transform);
	else if (r->current_object == LIGHT)
		r->world->light.position = matrix4_mult_tup4(transf_matrix,
				r->world->light.position);
	else if (r->current_shape)
	{
		shape = (t_shape *)r->current_shape->content;
		shape->transform = include_new_transformation(shape->transform,
				transf_matrix, r->transf_type);
		shape->i_transform = invert_matrix4(shape->transform);
	}
	render(r);
}

void	set_curr_obj(int keycode, t_root *r)
{
	if (keycode == XK_c)
		r->current_object = CAMERA;
	else if (keycode == XK_l)
		r->current_object = LIGHT;
	else if (keycode == XK_s)
	{
		r->current_object = SHAPE;
		if (r->current_shape)
			r->current_shape = r->current_shape->next;
		else
			r->current_shape = r->world->objects;
	}
}

void	print_transform(t_root *r)
{
	char	*t[10];

	t[0] = "No transformation";
	t[1] = "Rotate X";
	t[2] = "ROTATE Y";
	t[3] = "ROTATE Z";
	t[4] = "SCALE X";
	t[5] = "SCALE Y";
	t[6] = "SCALE Z";
	t[7] = "TRANSLATE X";
	t[8] = "TRANSLATE Y";
	t[9] = "TRANSLATE Z";
	ft_printf("Current transformation: %s\n", t[r->transf_type]);
}
