/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:40:06 by joamonte          #+#    #+#             */
/*   Updated: 2024/09/09 21:12:18 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	int_size(t_intersection *lst)
{
	int				count;
	t_intersection	*next_value;

	count = 0;
	next_value = lst;
	while (next_value)
	{
		count++;
		next_value = next_value->next;
	}
	return (count);
}

t_intersection	*intlast(t_intersection *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	int_add_front(t_intersection **lst, t_intersection *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	int_add_back(t_intersection **lst, t_intersection *new)
{
	if (!new)
		return (1);
	if (*lst == NULL)
		*lst = new;
	else
		intlast(*lst)->next = new;
	return (0);
}

void	intclear(t_intersection **lst)
{
	t_intersection	*buffer;

	while (*lst)
	{
		buffer = (*lst)->next;
		free(*lst);
		*lst = buffer;
	}
}
