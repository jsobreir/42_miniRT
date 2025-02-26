#include "minirt.h"

static int	count_words_multiple(const char *s, char *tokens)
{
	int			counter;
	size_t		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (ft_strchr(tokens, s[i]))
			i++;
		else
		{
			counter++;
			while (!ft_strchr(tokens, s[i]) && s[i])
				i++;
		}
	}
	return (counter);
}

static char	**memfree_multiple(char **ret, int n)
{
	while (n--)
		free(ret[n]);
	free(ret);
	return (NULL);
}

static char	**generate_ret_multiple(char const *s, char *tokens, int counter)
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
		while (ft_strchr(tokens, *s) && *s)
			s++;
		while (!ft_strchr(tokens, *s) && *s)
		{
			s++;
			i++;
		}
		ret[n] = (char *)malloc((i + 1) * sizeof(char));
		if (!ret[n])
			return (memfree_multiple(ret, n));
		n++;
		i++;
	}
	return (ret);
}

static char	**put_split_words_multiple(const char *s, char **ret, char *tokens, int counter)
{
	int		j;
	int		i;

	j = 0;
	while (j < counter)
	{
		while (ft_strchr(tokens, *s))
			s++;
		i = 0;
		while (!ft_strchr(tokens, *s) && *s)
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

char	**ft_split_multiple(char *s, char *tokens)
{
	char	**ret;
	int		counter;

	if (!s)
		return (0);
	counter = count_words_multiple(s, tokens);
	ret = generate_ret_multiple(s, tokens, counter);
	if (!ret)
		return (0);
	ret = put_split_words_multiple(s, ret, tokens, counter);
	free(s);
	return (ret);
}
