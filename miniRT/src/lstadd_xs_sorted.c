/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_xs_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndo-vale <ndo-vale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:16:22 by ndo-vale          #+#    #+#             */
/*   Updated: 2024/09/09 20:56:20 by ndo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_intersection	*lstadd_smallest(t_intersection **lst,
						t_intersection *new)
{
	t_intersection	*tmpnew;

	while (new)
	{
		if ((*lst)->t > new->t)
		{
			tmpnew = new->next;
			int_add_front(lst, new);
			new = tmpnew;
		}
		else
			break ;
	}
	return (new);
}

static void	lstinsert_sorted(t_intersection **lst, t_intersection *new)
{
	t_intersection	*tmplst;
	t_intersection	*tmpnew;

	tmplst = *lst;
	while (tmplst && new)
	{
		if (!tmplst->next)
		{
			tmplst->next = new;
			break ;
		}
		else if (tmplst->next->t > new->t)
		{
			tmpnew = new->next;
			new->next = tmplst->next;
			tmplst->next = new;
			new = tmpnew;
		}
		tmplst = tmplst->next;
	}
}

void	lstadd_xs_sorted(t_intersection **lst, t_intersection *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		new = lstadd_smallest(lst, new);
		if (!new)
			return ;
		lstinsert_sorted(lst, new);
	}
}
