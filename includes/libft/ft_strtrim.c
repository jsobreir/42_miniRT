/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:39:07 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/03 13:57:40 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

// int main (void)
// {
// 	printf("%s", ft_strtrim("abcd", ""));
// }
// int main (void)
// {
// 	char s1[] = "         ";
// 	printf("%s", ft_strtrim(s1, " "));
// }
// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	char	*strtrim;
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
// 		if (!(strtrim = ft_strtrim(s1, " ")))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strtrim);
// 		if (strtrim == s1)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 2)
// 	{
// 		char s1[] = "lorem ipsum dolor sit amet";
// 		if (!(strtrim = ft_strtrim(s1, "te")))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strtrim);
// 		if (strtrim == s1)
// 		if (strtrim == s1)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 5)
// 	{
// 		char s1[] = "          ";
// 		if (!(strtrim = ft_strtrim(s1, " ")))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strtrim);
// 		if (strtrim == s1)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	return (0);
// }	ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 3)
// 	{
// 		char s1[] = " lorem ipsum dolor sit amet";
// 		if (!(strtrim = ft_strtrim(s1, "l ")))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strtrim);
// 		if (strtrim == s1)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 4)
// 	{
// 		char s1[] = "lorem ipsum dolor sit amet";
// 		if (!(strtrim = ft_strtrim(s1, "tel")))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strtrim);
// 		