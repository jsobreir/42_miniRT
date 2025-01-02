/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:08:32 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/23 16:55:59 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	if (!s)
		return (0);
	ret = ft_strdup(s);
	if (!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	return (ret);
}

// char	function(unsigned int i, char c)
// {
// 	return (c = c + i);
// }
// int main (void)
// {
// 	char *s = "Joao";
// 	ft_putstr_fd(ft_strmapi(s, function), 1);
// }