/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:58:14 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/03 13:19:43 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*str;
	size_t	total_len;

	if (!s)
		return (NULL);
	str = (char *) s + start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(str) < len)
		total_len = ft_strlen(str);
	else
		total_len = len;
	ret = malloc((total_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, total_len + 1);
	return (ret);
}

// int main (void)
// {
// 	printf("%s\n", ft_substr("i just want this part #############", 5, 20));
// 	// printf("%s\n", ft_substr("kamikaze", 0, 10));
// 	// printf("%s\n", ft_substr("kamikaze", 1, 2));
// 	// printf("%s\n", ft_substr("kamikaze", 1, 1));
// 	// printf("%s\n", ft_substr("kamikaze", 1, 9));
// 	// printf("%s\n", ft_substr("kamikaze", 8, 8));
// 	// printf("%s\n", ft_substr("", 0, 0));
// 	// printf("%s\n", ft_substr("kamikaze", 0, 1));
// 	// printf("%s\n", ft_substr("i just want this part #############", 5, 20));
// }