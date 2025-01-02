/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:10:15 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/03 14:47:38 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*set;

	if (!f || !del || !lst)
		return (NULL);
	new_list = NULL;
	new_node = NULL;
	while (lst)
	{
		set = f(lst->content);
		new_node = ft_lstnew(set);
		if (!new_node)
		{
			del(set);
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void *map(void *content)
// {
//     char *str = (char *)content;
//     char *new_str = ft_strtrim(str, "Jo"); 

//     if (!new_str)
//         return (NULL);

//     return (new_str);
// }

// int main (void)
// {
// 	t_list	*lst = ft_lstnew("Joao ");
// 	t_list	*ret;

// 	lst->next = ft_lstnew("Sobreira");
// 	lst->next->next = ft_lstnew(" Barbot");
// 	ret = ft_lstmap(lst, &map, ft_lstdelone);

// 	while (ret)
// 	{
// 		printf("%s", ret->content);
// 		ret = ret->next;
// 	}
// }
