/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamonte <joamonte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:49 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/13 19:41:50 by joamonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	clean_exit(t_root *r, int exit_code)
{
	free_world(r->world);
	mlx_destroy_image(r->mlx, r->canvas->img);
	free(r->canvas);
	mlx_destroy_window(r->mlx, r->win);
	mlx_destroy_display(r->mlx);
	free(r->mlx);
	exit(exit_code);
	return (0);
}

void	exit_with_msg(char *msg, t_root *r, int exit_code)
{
	ft_putstr_fd(msg, 2);
	clean_exit(r, exit_code);
}

void	free_world(t_world *w)
{
	ft_lstclear(&w->objects, free);
	free(w->camera);
	free(w);
}
