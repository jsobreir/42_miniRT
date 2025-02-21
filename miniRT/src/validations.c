/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:14:30 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/17 15:47:30 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_color(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255)
		&& (b >= 0 && b <= 255))
		return (true);
	else
		return (false);
}

bool	is_vector(float x, float y, float z)
{
	if ((x >= -1.0f && x <= 1.0f) && (y >= -1.0f && y <= 1.0f)
		&& (z >= -1.0f && z <= 1.0f))
		return (true);
	else
		return (false);
}

bool	is_light(float l)
{
	if (l >= 0.0f && l <= 1.0f)
		return (true);
	else
		return (false);
}

int	is_duplicate(int id)
{
	static bool	flag_ambiente;
	static bool	flag_light;
	static bool	flag_camera;

	if ((flag_ambiente && id == AMBIENT)
		|| (flag_light && id == LIGHT)
		|| (flag_camera && id == CAMERA))
		return (-1);
	else if (id == AMBIENT)
	{
		flag_ambiente = true;
		return (id);
	}
	else if (id == LIGHT)
	{
		flag_light = true;
		return (id);
	}
	else if (id == CAMERA)
	{
		flag_camera = true;
		return (id);
	}
	else
		return (id);
}
