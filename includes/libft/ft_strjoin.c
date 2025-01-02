/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:09:18 by jsobreir          #+#    #+#             */
/*   Updated: 2024/04/22 12:31:01 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy (ret, s1, len1 + 1);
	ft_strlcpy (ret + len1, s2, len2 + 1);
	return (ret);
}

// int main(void)
// {
// 	// printf("%s\n", ft_strjoin("Joao ", "Barbot"));
// 	// printf("%s\n", ft_strjoin(0, "Barbot"));
// 	// printf("%s\n", ft_strjoin("Joao ", 0));
// 	// printf("%s\n", ft_strjoin(0, 0));

// 	char	s1[] = "lorem ipsum";
// 	char	s2[] = "dolor sit amet";
// 	printf("%s\n", ft_strjoin(s1, s2));
// 	printf("%s\n", ft_strjoin(s1[0] = '\0', s2));
// }