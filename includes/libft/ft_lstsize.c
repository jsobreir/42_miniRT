/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:53:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/23 16:55:27 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int main (void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("Joao ");
// 	lst->next = ft_lstnew("Sobreira ");
// 	lst->next->next = ft_lstnew("Barbot");
// 	// while (lst)
// 	// {
// 	// 	printf("%s", lst->content);
// 	// 	lst = lst->next;
// 	// }
// 	printf("%d", ft_lstsize(lst));
// }