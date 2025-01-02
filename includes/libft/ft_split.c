/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobreir <jsobreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:08:46 by jsobreir          #+#    #+#             */
/*   Updated: 2024/05/03 14:21:26 by jsobreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int			counter;
	size_t		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			counter++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (counter);
}

static char	**memfree(char **ret, int n)
{
	while (n--)
		free(ret[n]);
	free(ret);
	return (NULL);
}

static char	**generate_ret(char const *s, char c, int counter)
{
	char	**ret;
	int		i;
	int		n;

	n = 0;
	ret = (char **)malloc((counter + 1) * sizeof(char *));
	if (!ret)
		return (0);
	while (n < counter)
	{
		i = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			i++;
		}
		ret[n] = (char *)malloc((i + 1) * sizeof(char));
		if (!ret[n])
			return (memfree(ret, n));
		n++;
		i++;
	}
	return (ret);
}

static char	**put_split_words(const char *s, char **ret, char c, int counter)
{
	int		j;
	int		i;

	j = 0;
	while (j < counter)
	{
		while (*s == c)
			s++;
		i = 0;
		while (*s != c && *s)
		{
			ret[j][i] = *s;
			s++;
			i++;
		}
		ret[j][i] = '\0';
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		counter;

	if (!s)
		return (0);
	counter = count_words(s, c);
	ret = generate_ret(s, c, counter);
	if (!ret)
		return (0);
	ret = put_split_words(s, ret, c, counter);
	return (ret);
}

// int main(void)
// {
// 	char	**ret;
// 	int 	n;
// 	int 	j;
// 	int 	counter;
// 	char	c = ' ';
// 	char 	*string = "      split       this for   me  !       ";

// 	ret = ft_split(string, c);
// 	counter = count_words(string, c);

// 	n = 0;
// 	while (n < counter)
// 	{
// 		j = 0;
// 		while (ret[n][j] != 0)
// 		{
// 			printf("%c", ret[n][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		n++;
// 	}
// }
