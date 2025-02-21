/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 14:14:43 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/02 09:35:01 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrix.h"

void	print_matrix2(t_matrix2 a, bool cast_to_int)
{
	int	i;

	i = -1;
	while (++i < 2)
		print_tup2(a.t[i], cast_to_int);
}

void	print_matrix3(t_matrix3 a, bool cast_to_int)
{
	int	i;

	i = -1;
	while (++i < 3)
		print_tup3(a.t[i], cast_to_int);
}

void	print_matrix4(t_matrix4 a, bool cast_to_int)
{
	int	i;

	i = -1;
	while (++i < 4)
		print_tup4(a.t[i], cast_to_int);
}
