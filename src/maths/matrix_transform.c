/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaiva-f <bpaiva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:56:50 by bpaiva-f          #+#    #+#             */
/*   Updated: 2025/02/26 13:56:51 by bpaiva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mtx_rotate_x(t_matrix *mtx, float degrees)
{
	mtx->matrix[1][1] = cosf(degrees);
	mtx->matrix[1][2] = sinf(degrees) * -1;
	mtx->matrix[2][1] = sinf(degrees);
	mtx->matrix[2][2] = cosf(degrees);
}

void	mtx_rotate_y(t_matrix *mtx, float degrees)
{
	mtx->matrix[0][0] = cosf(degrees);
	mtx->matrix[0][2] = sinf(degrees);
	mtx->matrix[2][0] = sinf(degrees) * -1;
	mtx->matrix[2][2] = cosf(degrees);
}

void	mtx_rotate_z(t_matrix *mtx, float degrees)
{
	mtx->matrix[0][0] = cosf(degrees);
	mtx->matrix[0][1] = sinf(degrees) * -1;
	mtx->matrix[1][0] = sinf(degrees);
	mtx->matrix[1][1] = cosf(degrees);
}

t_matrix	*mtx_skew_symmetric(t_vec3 axis)
{
	t_matrix	*sk;

	sk = new_mtx(4, 4);
	sk->matrix[0][0] = 0;
	sk->matrix[0][1] = -axis.z;
	sk->matrix[0][2] = axis.y;
	sk->matrix[0][3] = 0;
	sk->matrix[1][0] = axis.z;
	sk->matrix[1][1] = 0;
	sk->matrix[1][2] = -axis.x;
	sk->matrix[1][3] = 0;
	sk->matrix[2][0] = -axis.y;
	sk->matrix[2][1] = axis.x;
	sk->matrix[2][2] = 0;
	sk->matrix[2][3] = 0;
	sk->matrix[3][0] = 0;
	sk->matrix[3][1] = 0;
	sk->matrix[3][2] = 0;
	sk->matrix[3][3] = 1;
	return (sk);
}

t_matrix	*mtx_skew_symmetric_squared(t_vec3 axis)
{
	t_matrix	*sk;

	sk = new_mtx(4, 4);
	sk->matrix[0][0] = - (axis.y * axis.y + axis.z * axis.z);
	sk->matrix[0][1] = axis.x * axis.y;
	sk->matrix[0][2] = axis.x * axis.z;
	sk->matrix[0][3] = 0;
	sk->matrix[1][0] = axis.x * axis.y;
	sk->matrix[1][1] = - (axis.x * axis.x + axis.z * axis.z);
	sk->matrix[1][2] = axis.y * axis.z;
	sk->matrix[1][3] = 0;
	sk->matrix[2][0] = axis.x * axis.z;
	sk->matrix[2][1] = axis.y * axis.z;
	sk->matrix[2][2] = - (axis.x * axis.x + axis.y * axis.y);
	sk->matrix[2][3] = 0;
	sk->matrix[3][0] = 0;
	sk->matrix[3][1] = 0;
	sk->matrix[3][2] = 0;
	sk->matrix[3][3] = 1;
	return (sk);
}
