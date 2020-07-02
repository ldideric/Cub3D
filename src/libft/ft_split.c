/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ldideric <ldideric@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 14:01:22 by ldideric       #+#    #+#                */
/*   Updated: 2020/03/06 11:59:08 by ldideric      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*ft_strcut(const char *s, int index, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s + index) + 1);
	if (!str)
		return (NULL);
	while (s[index] != c && s[index] != '\0')
	{
		str[i] = s[index];
		i++;
		index++;
	}
	str[i] = '\0';
	return (str);
}

static int		ft_words(char const *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	if (words == 0)
		return (1);
	return (words);
}

static char		**ft_strclear(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char		**split_ext(char **array, const char *s, char c)
{
	int		i;
	int		str_cntr;

	i = 0;
	str_cntr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			array[str_cntr] = ft_strcut(s, i, c);
			if (!array[str_cntr])
			{
				ft_strclear(array);
				return (NULL);
			}
			str_cntr++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	array[str_cntr] = NULL;
	return (array);
}

char			**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!array)
		return (NULL);
	array = split_ext(array, s, c);
	return (array);
}
