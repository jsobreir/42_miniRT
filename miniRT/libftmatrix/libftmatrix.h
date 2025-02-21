/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmatrix.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:21:18 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/11 09:13:21 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATRIX_H
# define LIBFTMATRIX_H

# include <stdio.h>
# include "stdbool.h"
# include "math.h"

# define EPSILON 0.0001
# define TVECTOR 0.0
# define TPOINT 1.0
# define TCOLOR 0.0
# define TINVALID -1.0

typedef union u_tup2
{
	struct
	{
		float	x;
		float	y;
	};
	float	e[2];
}	t_tup2;

typedef struct s_tup3
{
	float	e[3];
}	t_tup3;

typedef union u_tup4
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	};
	struct
	{
		float	r;
		float	g;
		float	b;
		float	a;
	};
	float	e[4];
}	t_tup4;

typedef union u_matrix2
{
	t_tup2	t[2];
	float	e[2][2];
}	t_matrix2;

typedef union u_matrix3
{
	t_tup3	t[3];
	float	e[3][3];
}	t_matrix3;

typedef union u_matrix4
{
	t_tup4	t[4];
	float	e[4][4];
}	t_matrix4;

//COMPARISONS
bool		tup2cmp(t_tup2 a, t_tup2 b);
bool		tup3cmp(t_tup3 a, t_tup3 b);
bool		tup4cmp(t_tup4 a, t_tup4 b);
bool		matrix2cmp(t_matrix2 a, t_matrix2 b);
bool		matrix3cmp(t_matrix3 a, t_matrix3 b);
bool		matrix4cmp(t_matrix4 a, t_matrix4 b);

//TUPLE_FACTORY
t_tup2		tup2(float x, float y);
t_tup3		tup3(float x, float y, float z);
t_tup4		tup4(float x, float y, float z, float w);
t_tup4		point(float x, float y, float z);
t_tup4		vector(float x, float y, float z);
t_tup4		color(float x, float y, float z);
t_tup4		invalid_tup4(void);

//TUPLE_OPERATIONS
t_tup4		add_tup4(t_tup4 a, t_tup4 b);
t_tup4		subtract_tup4(t_tup4 a, t_tup4 b);
t_tup4		negate_tup4(t_tup4 a);
t_tup4		multiply_tup4(t_tup4 a, float s);
t_tup4		divide_tup4(t_tup4 a, float s);
float		magnitude(t_tup4 a);
t_tup4		normalize(t_tup4 a);
float		dot(t_tup4 a, t_tup4 b);
t_tup4		cross(t_tup4 a, t_tup4 b);
t_tup4		hadamard(t_tup4 a, t_tup4 b);

//MATRIX_FACTORY
t_matrix2	matrix2(t_tup2 x, t_tup2 y);
t_matrix3	matrix3(t_tup3 x, t_tup3 y, t_tup3 z);
t_matrix4	matrix4(t_tup4 x, t_tup4 y, t_tup4 z, t_tup4 w);
t_matrix4	identity_matrix4(void);
t_matrix4	translation(float x, float y, float z);
t_matrix4	scaling(float x, float y, float z);
t_matrix4	shearing(t_tup2 x, t_tup2 y, t_tup2 z);
t_matrix4	rotation_x(float r);
t_matrix4	rotation_y(float r);
t_matrix4	rotation_z(float r);

//GET_FROM_MATRIX2
float		determinant2(t_matrix2 a);
//GET_FROM_MATRIX3
t_matrix2	submatrix3(t_matrix3 a, int i, int j);
float		cofactor3(t_matrix3 a, int i, int j);
float		determinant3(t_matrix3 a);
//GET_FROM_MATRIX4
bool		is_matrix4_invertible(t_matrix4 a);
t_tup4		get_column_from_matrix4(t_matrix4 a, int i);
t_matrix3	submatrix4(t_matrix4 a, int i, int j);
float		cofactor4(t_matrix4 a, int i, int j);
float		determinant4(t_matrix4 a);
//MATRIX4_OPERATIONS
t_matrix4	transpose_matrix4(t_matrix4 a);
t_tup4		matrix4_mult_tup4(t_matrix4 m, t_tup4 t);
t_matrix4	multiply_matrix4(t_matrix4 a, t_matrix4 b);
t_matrix4	invert_matrix4(t_matrix4 a);
t_matrix4	get_cofactor_matrix(t_matrix4 a);

//PRINT
void		print_tup2(t_tup2 a, bool cast_to_int);
void		print_tup3(t_tup3 a, bool cast_to_int);
void		print_tup4(t_tup4 a, bool cast_to_int);
void		print_matrix2(t_matrix2 a, bool cast_to_int);
void		print_matrix3(t_matrix3 a, bool cast_to_int);
void		print_matrix4(t_matrix4 a, bool cast_to_int);

#endif
