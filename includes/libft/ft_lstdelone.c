/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:26:47 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/23 16:37:14 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }
// int main (void)
// {
// 	t_list	*lst;
// 	lst = ft_lstnew("Joao ");
// 	lst->next = ft_lstnew("Sobreira ");
// 	lst->next->next = ft_lstnew("Barbot");
// 	t_list	*current = lst->next;  // Start from the beginning
// 	ft_lstdelone(lst, del);
// 	while (current)
// 	{
// 		printf("%s", (char *)current->content);  // Print the content
// 		current = current->next;  // Move to the next node
// 	}
// }